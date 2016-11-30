#include <iostream>

//POD Plain Old Data (POD) structure

struct Chunk
{
    void Init(std::size_t blockSize, unsigned char blocks);
    void* Allocate(std::size_t blockSize);
    void Deallocate(void* p, std::size_t blockSize);
    unsigned char* pData_;
    unsigned char firstAvailableBlock_, blocksAvailable_;
};

void Chunk::Init(std::size_t blockSize, unsigned char blocks)
{
    pData_ = new unsigned char[blockSize * blocks];
    firstAvailableBlock_ = 0;
    blocksAvailable_ = blocks;
    unsigned char i = 0;
    unsigned char *p = pData_;

    for (; i != blocks; p += blockSize) {
        *p = ++i;
    }
}

void* Chunk::Allocate(std::size_t blockSize)
{
    if (!blocksAvailable_) return 0;

    unsigned char* pResult = pData_ + (firstAvailableBlock_ * blockSize);

    firstAvailableBlock_ = *pResult;
    --blocksAvailable_;
    return pResult;
}

void Chunk::Deallocate(void* p, std::size_t blockSize)
{
    assert(p >= pData_);
    unsigned char* toRelease = static_cast<unsigned char*>(0);
    assert((toRelease - pData_) % blockSize == 0);

    *toRelease = firstAvailableBlock_;

    firstAvailableBlock_ = static_cast<unsigned char> ((toRelease - pData_) / blockSize);

    assert(firstAvailableBlock_ == (toRelease - pData_) / blockSize);

    ++blocksAvailable_;
}

class FixedAllocator
{
public:
    void* Allocate();

private:
    std::size_t blockSize_;
    unsigned char numBlocks_;
    typedef std::vector<Chunk> chunks;
    Chunks chunks_;
    Chunk* allocChunk_;
    Chunk* deallocChunk_;
};

void* FixedAllocator::Allocate()
{
    if (allocChunk_ == 0 || allocChunk_->blocksAvailable_ == 0)
    {
        Chunks::iterator i = chunks_.begin();
        for (;; ++i)
        {
            if (i == chunks_.end())
            {
                chunks_.reserve(chunks_.size() + 1);
                Chunk newChunk;
                newChunk.Init(blockSize_, numBlocks_);
                chunks_.push_back(newChunk);
                allocChunk_ = &chunks_.back();
                deallocChunk_ = & chunks_.back();
                break;
            }

            if (i->blocksAvailable_ > 0)
            {
                allocChunk_ = &*i;
                break;
            }
        }
    }
    assert(allocChunk_ != 0);
    assert(allocChunk_->blocksAvailable_ > 0);
    return allocChunk_->Allocate(blockSize_);
}

class SmallObjAllocator
{
public:
    SmallObjAllocator(
        std::size_t chunkSize,
        std::size_t maxObjectSize);

    void* Allocate(std::size_t numBytes);
    void Deallocate(void* p, std::size_t size);

private:
    std::vector<FixedAllocator> pool_;
    FixedAllocator* pLastAlloc_;
    FixedAllocator* pLastDealloc_;
};


class SmallObject
{
public:
    static void* operator new(std::size_t size);
    static void operator delete(void* p, std::size_t size); // void operator delete(void* p);
    virtual ~SmallObject() {}
};

typedef Singleton<SmallObjAllocator> MyAlloc;
void* SmallObject::operator new(std::size_t size)
{
    return MyAlloc::Instance().Allocate(size);
}

void SmallObject::operator delete(void* p, std::size_t size)
{
    MyAlloc::Instance().Deallocate(p, size);
}

//================================


