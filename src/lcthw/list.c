#include <stdio.h>
#include "dbg.h"
#include <lcthw/list.h>
#include <assert.h>


List *List_create(){

    return calloc(1, sizeof(List));
    
}

void List_destroy(List *list){

    if (list->first == NULL) {
        free(list);
        list = NULL;
        return;
    }
    
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
    
    if (list->first == NULL) {
        return;
    }
    ListNode *curnode = list->first;

    while (curnode != NULL){
        free(curnode->value);
        curnode->value = NULL;
        curnode = curnode->next;
    }    
    
}

void List_clear_destroy(List * list){

    List_clear(list);
    List_destroy(list);

}

void List_push(List * list, void *value){
    
    ListNode *new_node = calloc(1, sizeof(ListNode));
    check_mem(new_node);
    new_node->value = value;
    
    // handle empty
    if (list->count == 0){
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

    error:
    return;
        
}

void *List_pop(List * list){
    
    if (list->count == 0 ) return NULL;
 
    void *val = list->last->value;
    ListNode *prev = list->last->prev; 
    free(list->last);
    list->last = prev;
    list->count--;

    if (list->count == 0){
        list->first = NULL;
    }

    return val;
    
}

void List_unshift(List * list, void *value){

    ListNode *new_node = calloc(1, sizeof(ListNode));
    new_node->value = value;
    
    if (list->count == 0){
        list->first = new_node; 
        list->last = new_node; 
        list->count++;
        return;
    }

    // non-empty
    new_node->next = list->first;
    list->first->prev = new_node;
    list->first = new_node;
    list->count++;

}

void *List_shift(List * list){

    if (list->count == 0 ) return NULL;
 
    void *val = list->first->value;
    ListNode *next = list->first->next; 
    free(list->first);
    list->first = next;
    list->count--;

    if (list->count == 0){
        list->last = NULL;
    }

    return val;
    

}

void *List_remove(List * list, ListNode * node){

    // To dont get segfault in edge cases, you need pointer comparison 
    // and and checking the counts to handle edge cases appropriatly.
    
    // empty
    if (list->count == 0){
        return NULL;
    }
    // single 
    if (list->count == 1){
        // free(list->first);
        // free(list->last):
        list->first = NULL;
        list->last = NULL;
    }
    // first elemment
    else if (node == list->first){ 
        list->first = list->first->next;
    }
    // last elemnt
    else if (node == list->last){        
        list->last = list->last->prev;
    }
    // inbetween
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
    list->count--;
    
    return  node->value;

}

/*
*   Print all the states of the object.
*/ 
void List_debug(List *list){

    log_info("List->First: %p ",list->first);
    log_info("List->Last:  %p ",list->last);
    log_info("List->count: %d", list->count);


}


