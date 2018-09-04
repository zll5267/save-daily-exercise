/*
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "bitmap.h"

int dump_bitmap(bitmap_objects_t *bos)
{
    printf("=========\n");
    printf("num_of_objs:%d, num_of_bitmaps:%d\n", bos->num_of_objs, bos->num_of_bitmaps);
    for (int i = 0; i < bos->num_of_bitmaps; ++i) {
        printf("%x ", bos->bitmaps[i]);
    }
    printf("\n");
    printf("=========\n");
}

int clear_index(bitmap_objects_t *buffer, int index)
{
    if (index >= buffer->num_of_objs) {
        return -1;
    }
    int i_of_bitmap = index / (sizeof(BIT_MAP_TYPE) * 8);
    int offset_of_bitmap = index % (sizeof(BIT_MAP_TYPE) * 8);
    BIT_MAP_TYPE mask = 0x1 << offset_of_bitmap;
    //printf("test index:%d, i:%d, offset:%d, 0x%x\n", index, i_of_bitmap, offset_of_bitmap, mask);
    if (buffer->bitmaps[i_of_bitmap] & mask) {
        buffer->bitmaps[i_of_bitmap] &= ~mask;
        return 0;
    } else {
        printf("index(%d) already clear!\n", index);
        return -1;
    }
}

int set_index(bitmap_objects_t *buffer, int index)
{
    if (index >= buffer->num_of_objs) {
        return -1;
    }
    int i_of_bitmap = index / (sizeof(BIT_MAP_TYPE) * 8);
    int offset_of_bitmap = index % (sizeof(BIT_MAP_TYPE) * 8);
    BIT_MAP_TYPE mask = 0x1 << offset_of_bitmap;
    //printf("test index:%d, i:%d, offset:%d, 0x%x\n", index, i_of_bitmap, offset_of_bitmap, mask);
    if (!(buffer->bitmaps[i_of_bitmap] & mask)) {
        buffer->bitmaps[i_of_bitmap] |= mask;
        return 0;
    } else {
        printf("index(%d) already set!\n", index);
        return -1;
    }
}

int first_free_index(bitmap_objects_t *buffer)
{
    int index = -1;
    int current_index = 0;
    int found = 0;

    for (int i = 0; i < buffer->num_of_bitmaps; ++i) {
        if (found || current_index >= buffer->num_of_objs) {
            break;
        }
        BIT_MAP_TYPE b = buffer->bitmaps[i];
        for (int j = 0; j < sizeof(BIT_MAP_TYPE) * 8; ++j) {
            if (!(b & 0x1)) {
                found = 1;
                break;
            }
            b >>= 1;
            if(++current_index >= buffer->num_of_objs) {
                break;
            }
        }
    }

    if (current_index < buffer->num_of_objs) {
        if (set_index(buffer, current_index) < 0) {//Note: whether it is perfect to set here
            return index;
        }
        index = current_index;
    }
    return index;
}

int first_set_index(bitmap_objects_t *buffer)
{
    int index = -1;
    int current_index = 0;
    int found = 0;

    for (int i = 0; i < buffer->num_of_bitmaps; ++i) {
        if (found || current_index >= buffer->num_of_objs) {
            break;
        }
        BIT_MAP_TYPE b = buffer->bitmaps[i];
        for (int j = 0; j < sizeof(BIT_MAP_TYPE) * 8; ++j) {
            if ((b & 0x1)) {
                found = 1;
                break;
            }
            b >>= 1;
            if(++current_index >= buffer->num_of_objs) {
                break;
            }
        }
    }

    if (current_index < buffer->num_of_objs) {
        index = current_index;
    }
    return index;
}

int init_bitmap(int object_num, bitmap_objects_t *bos)
{
    if (bos == NULL || object_num <= 0) {
        printf("invalid params!\n");
        return -1;
    }
    int num_of_objs_in_one_type = sizeof(BIT_MAP_TYPE) * 8;
    int bitmap_num = (object_num + num_of_objs_in_one_type - 1) / (num_of_objs_in_one_type);

    int all_size = object_num * sizeof(OBJECT_TYPE) + bitmap_num * sizeof(BIT_MAP_TYPE);

    printf("test obj_num:%d, bitmap_num:%d,all_size:%d, nooiot:%d \n", object_num, bitmap_num, all_size, num_of_objs_in_one_type);

    bos->num_of_objs = object_num;
    bos->num_of_bitmaps = bitmap_num;
    bos->bitmaps = malloc(bitmap_num * sizeof(BIT_MAP_TYPE));
    bos->objects = malloc(object_num * sizeof(OBJECT_TYPE));
    return 0;
}

int uninit_bitmap(bitmap_objects_t *bos)
{
    //TODO check if all bitmap is free
    int f_s_index = first_set_index(bos);
    if(f_s_index != -1) {
        printf("the first set index is %d!\n", f_s_index);
        return -1;
    }

    bos->num_of_objs = 0;
    bos->num_of_bitmaps = 0;
    if (bos->bitmaps) {
        free(bos->bitmaps);
        bos->bitmaps = NULL;
    }
    if (bos->objects) {
        free(bos->objects);
        bos->objects = NULL;
    }
    return 0;
}

OBJECT_TYPE *alloc_obj(bitmap_objects_t *buffer)
{
    int index = first_free_index(buffer);
    if (index >= 0) {
        return &(buffer->objects[index]);
    }
    return NULL;
}

int free_obj(bitmap_objects_t *buffer, OBJECT_TYPE *obj)
{
    if (obj < buffer->objects || obj >= (buffer->objects + sizeof(OBJECT_TYPE) * buffer->num_of_objs)) {
        printf("error obj:%p\n", obj);
        return -1;
    }
    int index = obj - buffer->objects;
    //printf("index:%d, obj:%p, base:%p\n", index, obj, buffer->objects);
    return clear_index(buffer, index);
}

