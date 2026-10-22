#include <stdio.h>
#include "dbg.h"
#include <lcthw/list.h>


List *List_create(){
    
    List *list = (List *) malloc(sizeof(List));
    log_info("size: %d", sizeof(list));
    
    return list;
}

// void List_clear_destroy(List *list){
// }

void List_push(List * list, void *value){

    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->value = value;

    // handle empty
    if (list->first == NULL && list->last == NULL){
        list->first = new_node; 
        list->last = new_node; 
        list->count++;
        return;
    }
    
    // non-empty
    new_node->prev = list->last;
    list->last = new_node;
    list->count++;
    
}

void *List_pop(List * list){

}




