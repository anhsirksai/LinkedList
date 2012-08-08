//
//  list.h
//  CTest
//
//  Created by hailan on 8/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef CTest_list_h
#define CTest_list_h

#include <stdbool.h>

typedef int elem_type;

/*
 * link node structure
 */

struct link_node_t {
    elem_type data;
    struct link_node_t *next;
};
typedef struct link_node_t link_node;

/*
 * link list structure
 */

struct link_list_t {
    link_node *head;        /* head of list */
    link_node *tail;        /* tail of list */
    unsigned int length;    /* length of list, node counter */
};
typedef struct link_list_t link_list;

typedef void(*link_node_callback)(link_node *);

/*
 * link node operation
 */
link_node* link_node_make (elem_type data);
void link_node_free(link_node *node);
void link_node_visit(link_node *node);

/*
 * link list operation
 */
link_list *link_list_create(void);
void link_list_destroy(link_list *list);
void link_list_append(link_list *list, elem_type data);
void link_list_foreach(link_list *list, link_node_callback callback);
bool link_list_isempty(link_list *list);
void link_list_traverse(link_list *list);
//void link_list_insert_before(link_list *list, link_node *next, elem_type data);
//void link_list_insert_after(link_list *list, link_node *pre, elem_type data);
void link_list_delete(link_list *list, link_node *node);
link_node * link_list_find(link_list *list, elem_type data);
#endif
