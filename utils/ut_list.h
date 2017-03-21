/*
 * Description: 
 *     History: yang@haipo.me, 2017/03/21, create
 */

# ifndef _UT_LIST_H_
# define _UT_LIST_H_

typedef struct list_node {
    struct list_node *prev;
    struct list_node *next;
    void *value;
} list_node;

typedef struct list_iter {
    list_node *next;
    int direction;
} list_iter;

typedef struct list_t {
    list_node *head;
    list_node *tail;
    void *(*dup)(void *value);
    void (*free)(void *value);
    int (*compare)(void *value1, void *value2);
    unsigned long len;
} list_t;

# define list_len(l)        ((l)->len)
# define list_head(l)       ((l)->head)
# define list_tail(l)       ((l)->tail)
# define list_prev_node(n)  ((n)->prev)
# define list_next_node(n)  ((n)->next)
# define list_node_value(n) ((n)->value)

list_t *list_create(void);
void list_release(list_t *list);
list_t *list_add_node_head(list_t *list, void *value);
list_t *list_add_node_tail(list_t *list, void *value);
list_t *list_insert_node(list_t *list, list_node *pos, void *value, int before);
void list_rotate(list_t *list);
void list_delete(list_t *list, list_node *node);

# define LIST_START_HEAD 0
# define LIST_START_TAIL 1

list_iter *list_get_iterator(list_t *list, int direction);
list_node *list_next(list_iter *iter);
void list_rewind_head(list_t *list, list_iter *iter);
void list_rewind_tail(list_t *list, list_iter *iter);
void list_release_iterator(list_iter *iter);

list_t *list_dup(list_t *orig);
list_node *list_search(list_t *list, void *key);
list_node *list_index(list_t *list, long index);

# endif
