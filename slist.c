//
//  slist.c
//  SLinkList
//
//  Created by hailan on 8/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"


/* single link node operation */

slink_node *
slink_node_make(elem_type data) {
    slink_node *node = (slink_node *)malloc(sizeof(slink_node));
    assert(node != NULL);
    node->data = data;
    node->next = NULL;
    return node;
}

void
slink_node_free(slink_node *node) {
    free(node);
    node = NULL;
}

void
slink_node_visit(slink_node *node) {
    assert(node != NULL);
    printf("[%p | %d]\n", node, node->data);
}

/* single link list operation */

slink_list *
slink_list_create(void) {
    slink_list *list = (slink_list *)malloc(sizeof(slink_list));
    assert(list != NULL);
    list->head = slink_node_make(0);
    list->tail = slink_node_make(0);
    list->head->next = list->tail;
    list->length = 0;
    return list;
}

void
slink_list_destroy(slink_list *list) {
    slink_node *current = list->head->next;
    while (current != list->tail) {
        slink_node *next = current->next;
        slink_node_free(current);
        current = next;
    }
    slink_node_free(list->head);
    slink_node_free(list->tail);
    free(list);
    list = NULL;
}

void
slink_list_append(slink_list *list, elem_type data) {
    list->tail->data = data;
    slink_node *node = slink_node_make(0);
    list->tail->next = node;
    list->tail = node;
    list->length += 1;
}

void
slink_list_delete(slink_list *list, unsigned int index) {
    assert(index >=0 && index < list->length);
    slink_node *current = list->head->next;
    slink_node *pre = list->head;
    unsigned int i = 0;
    while (current != list->tail) {
        if (i == index) {
            break;
        }
        pre = current;
        current = current->next;
        i++;
    }
    pre->next = current->next;
    slink_node_free(current);
    list->length -= 1;
}

void
slink_list_foreach(slink_list *list, slink_list_callback callback) {
    slink_node *current = list->head->next;
    while (current != list->tail) {
        callback(current);
        current = current->next;
    }
}

void
slink_list_traverse(slink_list *list) {
    printf("===== The fields of list %p =====\n", list);
    slink_list_foreach(list, slink_node_visit);
}

void
slink_list_reverse(slink_list *list) {
    slink_node *pre = NULL;
    slink_node *current = list->head;
    slink_node *next = current->next;
    while (current != NULL) {
        current->next = pre;
        pre = current;
        current = next;
        next = (next==NULL ? NULL : next->next);
    }
    slink_node *node = list->head;
    list->head = list->tail;
    list->tail = node;
}

/* single link list test */

void
slink_list_print(slink_list *list) {
    printf("===== single link list %p =====\n", list);
    printf("length %d\n", list->length);
    printf("head [%p|%d]-->", list->head, list->head->data);
    slink_node *current = list->head->next;
    while (current != list->tail) {
        printf("[%p|%d]-->", current, current->data);
        current = current->next;
    }
    printf("tail [%p|%d]\n", list->tail, list->tail->data);
}

void
slink_list_test_main(void) {
    slink_list *list = slink_list_create();
    slink_list_print(list);
    
    slink_list_append(list, 12);
    slink_list_append(list, 13);
    slink_list_append(list, 14);
    slink_list_print(list);
    
    slink_list_delete(list, 2);
    slink_list_print(list);
    
    slink_list_traverse(list);
    
    slink_list_reverse(list);
    slink_list_print(list);
    
    slink_list_destroy(list);
    
}

