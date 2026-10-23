#include <stdio.h>
#include "dbg.h"
#include <lcthw/list.h>
#include <assert.h>


List *List_create(){

    List *list = (List *) malloc(sizeof(List));    
    return list;
    
}

void List_destroy(List *list){

    ListNode *curnode = list->first;

    while (curnode != NULL){
        curnode = curnode->next;
        free(list->first->value);
        free(list->first);
        list->first = curnode;
    }        
    free(list);
    list = NULL;

}

void List_clear(List *list){
    
    ListNode *curnode = list->first;

    while (curnode != NULL){
        free(curnode->value);
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

void List_unshift(List * list, void *value){

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
    new_node->prev = NULL;
    new_node->next = list->first;
    list->first = new_node;
    list->count++;

}

void *List_shift(List * list){

    void *return_value_ptr = NULL;
    if (list->count == 0 ) return return_value_ptr;

    return_value_ptr = list->first->value;
    list->first = list->first->next;
    list->count--;

    return return_value_ptr;

}

void *List_remove(List * list, ListNode * node){

    node->prev->next = node->next;
    node->next->prev = node->prev;
    list->count--;

    return node->value;

}

