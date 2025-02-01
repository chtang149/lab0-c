#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
/*Past Test*/
/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
//  cppcheck-suppress nullPointer
 */

/* Create an empty queue */
struct list_head *q_new()
{
    struct list_head *head =
        (struct list_head *) malloc(sizeof(struct list_head));
    if (!head) {
        return NULL;
    }
    INIT_LIST_HEAD(head);
    return head;
}

/* Free all storage used by queue */
void q_free(struct list_head *head)
{
    if (!head)
        return;
    element_t *entry, *safe;
    list_for_each_entry_safe (entry, safe, head, list)
        q_release_element(entry);
    free(head);
}

static inline element_t *q_new_elem(char *s)
{
    element_t *elem = malloc(sizeof(element_t));
    if (!elem)
        return NULL;

    char *tmp = strdup(s);
    if (!tmp) {
        free(elem);
        return NULL;
    }

    elem->value = tmp;
    return elem;
}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    if (!head || !s) {
        return false;
    }
    element_t *node = q_new_elem(s);
    if (!node) {
        return false;
    }
    // element_t *node = malloc(sizeof(element_t));
    // if (!node) {
    //     return false;
    // }
    // int len = strlen(s) + 1;
    // node->value = malloc(sizeof(char) * len);
    // if (!node->value) {
    //     free(node); /*!!!!REMEMBER TO FREE "node"*/
    //     return false;
    // }
    // strncpy(node->value, s, len);

    list_add(&node->list, head);
    return true;
    // return true;
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    if (!head || !s) {
        return false;
    }
    element_t *node = q_new_elem(s);
    if (!node) {
        return false;
    }
    // element_t *node = malloc(sizeof(element_t));
    // if (!node) {
    //     return false;
    // }
    // int len = strlen(s) + 1;
    // node->value = malloc(sizeof(char) * len);
    // if (!node->value) {
    //     free(node); /*!!!!REMEMBER TO FREE "node"*/
    //     return false;
    // }
    // strncpy(node->value, s, len);
    list_add_tail(&node->list, head);
    return true;
    // return true;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    if (!head || list_empty(head))
        return NULL;
    element_t *remove_node = list_entry(head->next, element_t, list);
    if (bufsize) {
        strncpy(sp, remove_node->value, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }
    list_del(&remove_node->list);
    return remove_node;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    if (!head || list_empty(head)) {
        return NULL;
    }
    element_t *lentry = list_last_entry(head, element_t, list);
    if (sp) {
        snprintf(sp, bufsize, "%s", lentry->value);
    }

    // memcpy(sp, fentry->value, bufsize);
    list_del(head->prev);
    return lentry;
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if (!head)
        return 0;

    int len = 0;
    struct list_head *li;

    list_for_each (li, head)
        len++;
    return len;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head)
{
    struct list_head *node = NULL, *prev = NULL;
    node = head->prev;
    prev = head;
    head->prev = head->next;
    head->next = node;
    for (; node != (head); prev = node, node = node->next) {
        node->next = node->prev;
        node->prev = prev;
    }
}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
