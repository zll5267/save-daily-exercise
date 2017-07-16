// Copyright 2017 xxx Inc. All Rights Reserved.
// Author:
//
// Description:

#ifndef UNIT_TEST_CMOCKA_CMAKE_BASE_MY_LIB_H
#define UNIT_TEST_CMOCKA_CMAKE_BASE_MY_LIB_H

#include <string.h>

#define MY_MEMCPY(...)     memcpy(__VA_ARGS__)
#define MY_MEMCMP(...)     memcmp(__VA_ARGS__)
#define MY_MEMSET(...)     memset(__VA_ARGS__)
#define MY_STRLEN(...)     strlen(__VA_ARGS__)
#define MY_SNPRINTF(...)   snprintf(__VA_ARGS__)

typedef enum _errcode_enum {
    MY_OK,
    MY_ERR_FAILED = -10000,
    MY_ERR_INVALID_PARAMETER,
    MY_ERR_MEMORY_OVERLOW,
    MY_ERR_WOULD_BLOCK,
    MY_ERR_PROFILE_INVALID,
} my_errcode_t;

#endif // UNIT_TEST_CMOCKA_CMAKE_BASE_MY_LIB_H
