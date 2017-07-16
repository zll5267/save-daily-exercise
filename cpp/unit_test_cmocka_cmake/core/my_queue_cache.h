// Copyright 2017 xxx Inc. All Rights Reserved.
// Author: xxxxxx
//
// Description:

#ifndef UNIT_TEST_CMOCKA_CMAKE_CORE_MY_QUEUE_CACHE_H
#define UNIT_TEST_CMOCKA_CMAKE_CORE_MY_QUEUE_CACHE_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *my_qcache_handler;

my_qcache_handler my_qcache_create(void);

int my_qcache_push(my_qcache_handler cache, void *data);

void *my_qcache_top(my_qcache_handler cache);

void *my_qcache_pop(my_qcache_handler cache);

size_t my_qcache_length(my_qcache_handler cache);

void my_qcache_destroy(my_qcache_handler cache);

#ifdef __cplusplus
}
#endif

#endif // UNIT_TEST_CMOCKA_CMAKE_CORE_MY_QUEUE_CACHE_H
