#MESSAGE(STATUS ${CMAKE_CURRENT_LIST_DIR})
SET(TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/../../)

#SET(TEST_NAME lightduer_queue_cache_test)
SET(TEST_FILE ${TEST_DIR}/core/my_queue_cache.c)
SET(TEST_SRC_LIST
    ${TEST_SRC_LIST}
    ${TEST_FILE}
    ${CMAKE_CURRENT_LIST_DIR}/my_queue_cache_test.c
    CACHE INTERNAL
    "the compile file list"
)
