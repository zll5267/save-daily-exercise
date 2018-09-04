#ifndef __BITMAP__H_

#define OBJECT_TYPE int

#define BIT_MAP_TYPE unsigned char

typedef struct bitmap_objects_s {
    int num_of_objs;
    int num_of_bitmaps;
    BIT_MAP_TYPE *bitmaps;
    OBJECT_TYPE *objects;
} bitmap_objects_t;

int dump_bitmap(bitmap_objects_t *bos);

int first_set_index(bitmap_objects_t *buffer);

int init_bitmap(int object_num, bitmap_objects_t *bos);

int uninit_bitmap(bitmap_objects_t *bos);

OBJECT_TYPE *alloc_obj(bitmap_objects_t *buffer);

int free_obj(bitmap_objects_t *buffer, OBJECT_TYPE *obj);

#endif // __BITMAP__H_
