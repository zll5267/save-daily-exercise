#include "stdio.h"
#include "bitmap.h"

static bitmap_objects_t bitmap_objects;

int main()
{
    printf("init result:%d\n", init_bitmap(34, &bitmap_objects));

    dump_bitmap(&bitmap_objects);
    printf("firt set result:%d\n", first_set_index(&bitmap_objects));

    OBJECT_TYPE *obj = NULL;
    for (int i = 0; i < bitmap_objects.num_of_objs; ++i) {
    //for (int i = 0; i < 30; ++i) {
        obj = alloc_obj(&bitmap_objects);
    }
    dump_bitmap(&bitmap_objects);

    printf("firt set result:%d\n", first_set_index(&bitmap_objects));
    obj = bitmap_objects.objects;
    //for (int i = 0; i < bitmap_objects.num_of_objs; ++i) {
    for (int i = 0; i < 30; ++i) {
        free_obj(&bitmap_objects, obj++);
    }
    printf("firt set result:%d\n", first_set_index(&bitmap_objects));
    dump_bitmap(&bitmap_objects);
    printf("firt set result:%d\n", first_set_index(&bitmap_objects));
    free_obj(&bitmap_objects, obj++);
    free_obj(&bitmap_objects, obj++);
    free_obj(&bitmap_objects, obj++);
    free_obj(&bitmap_objects, obj++);
    printf("firt set result:%d\n", first_set_index(&bitmap_objects));
    printf("uninit result:%d\n", uninit_bitmap(&bitmap_objects));
}

