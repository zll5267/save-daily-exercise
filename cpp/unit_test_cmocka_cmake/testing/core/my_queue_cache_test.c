#include "test.h"
#include <string.h>
#include "base/my_lib.h"
#include "core/my_queue_cache.h"

typedef struct QCache {
    void* _header;
    void* _tail;
    size_t _length;
} QCache;

typedef struct QNode {
    void* _data;
    void* _next;
} QNode;

const static size_t qcache_size = sizeof(QCache);
const static size_t qnode_size = sizeof(QNode);

extern void* my_malloc(size_t size) {
    check_expected(size);
    return mock_ptr_type(void*);
}

extern void my_free(void* ptr) {
    check_expected(ptr);
}

static int create_qcache(void** state) {
    char* buffer = test_malloc(qcache_size);
    memset(buffer, 0, qcache_size);
    *state = buffer;
    return 0;
}

static int destroy_qcache(void** state) {
    test_free(*state);
    return 0;
}

void my_qcache_create_test(void** state) {
    //begin create fail
    expect_value(my_malloc, size, qcache_size);
    will_return(my_malloc, NULL);
    my_qcache_handler result_1 = my_qcache_create();
    assert_ptr_equal(result_1, NULL);
    //end create fail
    //begin create success
    char* buffer = test_malloc(qcache_size);
    for (int i = 0; i < qcache_size; ++i) {
        buffer[i] = 2;
    }
    for (int i = 0; i < qcache_size; ++i) {
        assert_int_equal(buffer[i], 2);
    }

    expect_value(my_malloc, size, qcache_size);
    will_return(my_malloc, buffer);

    my_qcache_handler result_2 = my_qcache_create();
    assert_ptr_equal(result_2, buffer);
    for (int i = 0; i < qcache_size; ++i) {
        assert_int_equal(buffer[i], 0);
    }
    test_free(buffer);
    //end create success
}

void my_qcache_push_test(void** state) {
    //begin qcache handler is null
    int result_1 = my_qcache_push(NULL, NULL);

    assert_int_equal(result_1, MY_ERR_INVALID_PARAMETER);
    //end qcache handler is null
    QCache* p_qcache = (QCache*)(*state);
    //begin qcache malloc fail
    expect_value(my_malloc, size, qnode_size);
    will_return(my_malloc, NULL);
    int result_2 = my_qcache_push(p_qcache, NULL);

    assert_int_equal(result_2, MY_ERR_MEMORY_OVERLOW);
    //end qcache malloc fail
    QNode* node1 = test_malloc(qnode_size);
    QNode* node2 = test_malloc(qnode_size);
    //begin qcache push first node
    expect_value(my_malloc, size, qnode_size);
    will_return(my_malloc, node1);
    int result_3 = my_qcache_push(p_qcache, (void*)0x1234);

    assert_int_equal(result_3, MY_OK);
    assert_ptr_equal(node1->_data, 0x1234);
    assert_ptr_equal(node1->_next, NULL);
    assert_ptr_equal(p_qcache->_header, node1);
    assert_ptr_equal(p_qcache->_tail, node1);
    assert_int_equal(p_qcache->_length, 1);
    //end qcache push first node
    //begin qcache push second node
    expect_value(my_malloc, size, qnode_size);
    will_return(my_malloc, node2);
    int result_4 = my_qcache_push(p_qcache, (void*)0x5678);

    assert_int_equal(result_4, MY_OK);
    assert_ptr_equal(node1->_data, 0x1234);
    assert_ptr_equal(node1->_next, node2);
    assert_ptr_equal(node2->_data, 0x5678);
    assert_ptr_equal(node2->_next, NULL);
    assert_ptr_equal(p_qcache->_header, node1);
    assert_ptr_equal(p_qcache->_tail, node2);
    assert_int_equal(p_qcache->_length, 2);
    //end qcache push second node
    test_free(node1);
    test_free(node2);
}

void my_qcache_length_test(void** state) {
    //begin qcache handler is NULL
    size_t result_1 = my_qcache_length(NULL);
    assert_int_equal(result_1, 0);
    //end qcache handler is NULL
    QCache* p_qcache = (QCache*)(*state);
    //begin qcache with one node
    p_qcache->_length = 1;
    size_t result_2 = my_qcache_length(*state);
    assert_int_equal(result_2, 1);
    //end qcache with one node
    p_qcache->_length = 10;
    size_t result_3 = my_qcache_length(*state);
    assert_int_equal(result_3, 10);
}

void my_qcache_top_test(void** state) {
    //begin qcache handler is NULL
    void* result_1 = my_qcache_top(NULL);
    assert_ptr_equal(result_1, NULL);
    //end qcache handler is NULL
    //begin qcache without node
    void* result_2 = my_qcache_top(*state);
    assert_ptr_equal(result_2, NULL);
    //end qcache without node
    //begin qcache with one node
    QNode* node1 = test_malloc(qnode_size);
    node1->_data = (void*)0x7856;
    QCache* p_qcache = (QCache*)(*state);
    p_qcache->_header = p_qcache->_tail = node1;
    void* result_3 = my_qcache_top(*state);
    assert_ptr_equal(result_3, 0x7856);
    //end qcache without node
    test_free(node1);
    //end qcache with one node
}

void my_qcache_pop_test(void** state) {
    //begin qcache handler is NULL
    void* result_1 = my_qcache_pop(NULL);
    assert_ptr_equal(result_1, NULL);
    //end qcache handler is NULL
    //begin qcache without node
    void* result_2 = my_qcache_pop(*state);
    assert_ptr_equal(result_2, NULL);
    //end qcache without node
    QCache* p_qcache = (QCache*)(*state);
    QNode* node1 = test_malloc(qnode_size);
    QNode* node2 = test_malloc(qnode_size);
    //begin qcache with two nodes
    node1->_data = (void*)0xABCD;
    node1->_next = node2;
    node2->_data = (void*)0x11AABBDD;
    node2->_next = NULL;
    p_qcache->_length = 2;
    p_qcache->_header = node1;
    p_qcache->_tail = node2;

    expect_value(my_free, ptr, node1);
    void* result_3 = my_qcache_pop(*state);
    assert_ptr_equal(result_3, 0xABCD);
    assert_ptr_equal(p_qcache->_header, node2);
    assert_ptr_equal(p_qcache->_tail, node2);
    assert_int_equal(p_qcache->_length, 1);
    //end qcache with two nodes
    //begin qcache with one node
    expect_value(my_free, ptr, node2);
    void* result_4 = my_qcache_pop(*state);
    assert_ptr_equal(result_4, 0x11AABBDD);
    assert_ptr_equal(p_qcache->_header, NULL);
    assert_ptr_equal(p_qcache->_tail, NULL);
    assert_int_equal(p_qcache->_length, 0);
    //end qcache with one node
    test_free(node1);
    test_free(node2);
}

void my_qcache_destroy_test(void** state) {
    //begin qcache handler is null
    //no test need
    //end qcache handler is null
    //begin qcache without node
    expect_value(my_free, ptr, *state);
    my_qcache_destroy((my_qcache_handler)*state);

    char* buffer = (char*)(*state);
    for (int i = 0; i < qcache_size; ++i) {
        assert_int_equal(buffer[i], 0);
    }
    //end qcache without node
    //begin qcache with one  node
    QNode* node = test_malloc(qnode_size);
    node->_data = NULL;
    node->_next = NULL;

    QCache* p_qcache = (QCache*)(*state);
    p_qcache->_header = p_qcache->_tail = node;
    p_qcache->_length = 1;

    expect_value(my_free, ptr, node);
    expect_value(my_free, ptr, *state);
    my_qcache_destroy((my_qcache_handler)*state);
    assert_ptr_equal(p_qcache->_header, NULL);
    assert_ptr_equal(p_qcache->_tail, NULL);
    assert_ptr_equal(p_qcache->_length, 0);

    test_free(node);
    //end qcache with one  node
}

CMOCKA_UNIT_TEST(my_qcache_create_test);
CMOCKA_UNIT_TEST_SETUP_TEARDOWN(my_qcache_destroy_test, create_qcache, destroy_qcache);
CMOCKA_UNIT_TEST_SETUP_TEARDOWN(my_qcache_push_test, create_qcache, destroy_qcache);
CMOCKA_UNIT_TEST_SETUP_TEARDOWN(my_qcache_length_test, create_qcache, destroy_qcache);
CMOCKA_UNIT_TEST_SETUP_TEARDOWN(my_qcache_top_test, create_qcache, destroy_qcache);
CMOCKA_UNIT_TEST_SETUP_TEARDOWN(my_qcache_pop_test, create_qcache, destroy_qcache);

