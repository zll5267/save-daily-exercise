// Copyright 2017 xxxx Inc. All Rights Reserved.
// Author:
//
// Description:

#ifndef UNIT_TEST_CMOCKA_CMAKE_BASE_MY_MEMORY_H
#define UNIT_TEST_CMOCKA_CMAKE_BASE_MY_MEMORY_H


#define MY_MALLOC(_size) my_malloc(_size)
#define MY_REALLOC(_ptr, _size) my_realloc(_ptr, _size)
#define MY_FREE(_ptr) my_free(_ptr)
#define MY_CALLOC(_size, _num) my_MALLOC((_size) * (_num))

#ifdef __cplusplus
extern "C" {
#endif

/*
 * malloc function
 *
 * @Param size, size_t, the expected size of the memory
 * @Return the alloced memory pointer
 */
extern void* my_malloc(size_t size);

/*
 * realloc function
 *
 * @Param ptr, void *, the old alloced memory
 * @Param size, size_t, the expected size of the memory
 * @Return the new alloced memory pointer
 */
extern void* my_realloc(void* ptr, size_t size);

/*
 * free function
 *
 * @Param ptr, void *, the alloced memory
 */
extern void my_free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif // UNIT_TEST_CMOCKA_CMAKE_BASE_MY_MEMORY_H
