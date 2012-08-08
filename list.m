//
//  list.c
//  CTest
//
//  Created by hailan on 8/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

link_node *
link_node_make(elem_type data) {
    link_node *node = (link_node *) malloc(sizeof(link_node));
    assert(node != NULL);
    node->data = data;
    node->next = NULL;
    return node;
}

void
link_node_free(link_node *node) {
    free(node);
    node = NULL;
}

void
link_node_visit(link_node *node) {
    assert(node != NULL);
    /* TODO: beautify output. */
    printf("element field is %d\n", node->data);
}

/*
 * link list operation
 */

link_list *link_list_create(void) {
    link_list *list = (link_list *) malloc(sizeof(link_list));
    assert(list != NULL);
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
}

void
link_list_destroy(link_list *list) {
    if (list != NULL) {
    	link_node *current = list->head;
    	while (current != NULL) {
    		link_node *nextnode = current->next;
    		link_node_free(current);
    		current = nextnode;
    	}
    	free(list);
    	list = NULL;
    }
}

void
link_list_append(link_list *list, elem_type data) {
    link_node *newnode = link_node_make(data);
    assert(list != NULL);
    if (list->tail == NULL) {
    	list->head = list->tail = newnode;
    } else {
    	list->tail->next = newnode;
    	list->tail = newnode;
    }
    list->length++;
} 

void
link_list_foreach(link_list *list, link_node_callback callback) {
    if (list != NULL) {
        link_node *current = list->head;
        while (current != NULL) {
            callback(current);
            current = current->next;
        }
    }
}

bool 
link_list_isempty(link_list *list) {
    return list->length == 0;
}

void
link_list_traverse(link_list *list) {
    link_list_foreach(list, link_node_visit);
}

void
link_list_delete(link_list *list, link_node *node) {
    if (list != NULL) {
        link_node *current = list->head;
        link_node *pre = NULL;
        while (current != NULL && current != node) {
            pre = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("link node %p does not exist in the link list.\n", node);
        } else {
            if (node == list->head) {
                list->head = node->next;
            } else {
                pre->next = node->next;
                if (node == list->tail) {
                    list->tail = pre;
                }
            }
            link_node_free(node);
            list->length--;
        }
    }
}

link_node * link_list_find(link_list *list, elem_type data) {
    link_node *current = list->head;
    while (current) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

