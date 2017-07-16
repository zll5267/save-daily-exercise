#include "core/my_queue_cache.h"
#include "base/my_memory.h"
#include "base/my_lib.h"

typedef struct _my_qcnode_s {
    void *                  _data;
    struct _my_qcnode_s * _next;
} my_qcnode_t;

typedef struct _my_qcache_s {
    my_qcnode_t   *_head;
    my_qcnode_t   *_tail;
    size_t          _length;
} my_qcache_t;

static my_qcnode_t *my_qcache_node_create(void *data)
{
    my_qcnode_t *node = (my_qcnode_t *)MY_MALLOC(sizeof(my_qcnode_t));
    if (node) {
        node->_data = data;
        node->_next = NULL;
    }
    return node;
}

my_qcache_handler my_qcache_create(void)
{
    my_qcache_t *cache = (my_qcache_t *)MY_MALLOC(sizeof(my_qcache_t));
    if (cache) {
        MY_MEMSET(cache, 0, sizeof(my_qcache_t));
    }
    return (my_qcache_handler)cache;
}

int my_qcache_push(my_qcache_handler cache, void *data)
{
    int rs = MY_ERR_INVALID_PARAMETER;
    my_qcache_t *p = (my_qcache_t *)cache;
    my_qcnode_t *q = NULL;

    do {
        if (p == NULL) {
            break;
        }

        q = my_qcache_node_create(data);
        if (q == NULL) {
            rs = MY_ERR_MEMORY_OVERLOW;
            break;
        }

        if (p->_tail != NULL) {
            p->_tail->_next = q;
            p->_tail = q;
        } else {
            p->_head = p->_tail = q;
        }

        p->_length++;

        rs = MY_OK;
    } while (0);

    return rs;
}

size_t my_qcache_length(my_qcache_handler cache)
{
    my_qcache_t *p = (my_qcache_t *)cache;
    return (p != NULL) ? p->_length : 0;
}

void *my_qcache_top(my_qcache_handler cache)
{
    my_qcache_t *p = (my_qcache_t *)cache;
    return p != NULL && p->_head != NULL ? p->_head->_data : NULL;
}


void *my_qcache_pop(my_qcache_handler cache)
{
    my_qcache_t *p = (my_qcache_t *)cache;
    my_qcnode_t *q = NULL;
    void *rs = NULL;

    if (p && p->_head) {
        q = p->_head;
        p->_head = q->_next;
        rs = q->_data;
        if (--(p->_length) == 0) {
            p->_tail = NULL;
        }
        MY_FREE(q);
    }

    return rs;
}

void my_qcache_destroy(my_qcache_handler cache)
{
    my_qcache_t *p = (my_qcache_t *)cache;
    my_qcnode_t *q = p != NULL ? p->_head : NULL;
    my_qcnode_t *r;

    while (q) {
        r = q;
        q = q->_next;
        MY_FREE(r);
    }

    if (p) {
        MY_MEMSET(p, 0, sizeof(my_qcache_t));
        MY_FREE(p);
    }
}
