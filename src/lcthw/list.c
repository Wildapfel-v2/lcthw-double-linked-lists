#include <stdio.h>
#include "dbg.h"
#include <lcthw/list.h>


List *List_create(){

    List *list = (List *) malloc(sizeof(List));    
    return list;
    
}

void List_clear_destroy(List *list){

}

void List_destroy(List *list){

}

void List_clear(List *list){

    ListNode *curnode = list->first;
    
    while (curnode != NULL){
        curnode->value = NULL;
        curnode = curnode->next;
    }    
    
}

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
    new_node->prev->next = new_node;
    list->last = new_node;
    list->count++;
        
}

void *List_pop(List * list){
    
    void *return_value_ptr = NULL;
    if (list->count == 0 ) return return_value_ptr;

    return_value_ptr = list->last->value;
    list->last = list->last->prev;
    list->count--;

    return return_value_ptr;
    
}
