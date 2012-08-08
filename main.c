//
//  main.c
//  CTest
//
//  Created by hailan on 8/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[])
{
    elem_type data = 10;
    link_node *node = link_node_make(data);
    link_node_visit(node);
    link_node_free(node);
    
    link_list *list = link_list_create();
    link_list_append(list, 1);
    link_list_append(list, 2);
    link_list_append(list, 3);
    
    link_list_delete(list, link_list_find(list, 4));
    link_list_delete(list, link_node_make(10));
    //link_list_delete(list, link_list_find(list, 1));
    
    link_list_traverse(list);
    link_list_destroy(list);


    return 0;
}
