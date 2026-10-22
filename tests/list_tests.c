#include "minunit.h"
#include <assert.h>
#include <lcthw/list.h>
#include <string.h>
#include<stdio.h>

static List *list = NULL;

static char *s1 = NULL;
static char *s2 = NULL;
static char *s3 = NULL;

char *test_create(){
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");
    return NULL;
}

<<<<<<< Updated upstream
// char *test_destroy(){
//     List_clear_destroy(list);
=======
// char *test_clear(){

//     List_push(list, test1);
//     mu_assert(List_last(list) == test1, "Wrong last value.");
//     List_push(list, test2);
//     mu_assert(List_last(list) == test2, "Wrong last value");
//     List_push(list, test3);
//     mu_assert(List_last(list) == test3, "Wrong last value");
    
//     List_clear(list);
//     mu_assert(List_count(list) == 3, "Count doenst math");
//     mu_assert(list->first->value == NULL, "Count doenst math");
//     mu_assert(list->first->next->value == NULL, "Count doenst math");
//     mu_assert(list->first->next->next->value == NULL, "Count doenst math");

>>>>>>> Stashed changes
//     return NULL;
// }

// char *test_destroy(){
//     return NULL;
// }


// // char *test_destroy(){
// //     List_clear_destroy(list);
// //     return NULL;
// // }

char *test_push_pop(char *test1, char *test2, char *test3){
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value.");
    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value");
    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value.");
    mu_assert(List_count(list) == 3, "Wrong count on push.");
    char *val = List_pop(list);
    mu_assert(val == test3, "Wrong value on pop.");
    val = List_pop(list);
    mu_assert(val == test2, "Wrong value on pop.");
    val = List_pop(list);
    mu_assert(val == test1, "Wrong value on pop.");
    mu_assert(List_count(list) == 0, "Wrong count after pop.");
    return NULL;
}

// char *test_unshift(){
//     List_unshift(list, test1);
//     mu_assert(List_first(list) == test1, "Wrong first value.");
//     List_unshift(list, test2);
//     mu_assert(List_first(list) == test2, "Wrong first value");
//     List_unshift(list, test3);
//     mu_assert(List_first(list) == test3, "Wrong last value.");
//     mu_assert(List_count(list) == 3, "Wrong count on unshift.");
//     return NULL;
// }

// char *test_remove(){
//     // we only need to test the middle remove case since push/shift
//     // already tests the other cases
//     char *val = List_remove(list, list->first->next);
//     mu_assert(val == test2, "Wrong removed element.");
//     mu_assert(List_count(list) == 2, "Wrong count after remove.");
//     mu_assert(List_first(list) == test3, "Wrong first after remove.");
//     mu_assert(List_last(list) == test1, "Wrong last after remove.");
//     return NULL;
// }

// char *test_shift(){
//     mu_assert(List_count(list) != 0, "Wrong count before shift.");
//     char *val = List_shift(list);
//     mu_assert(val == test3, "Wrong value on shift.");
//     val = List_shift(list);
//     mu_assert(val == test1, "Wrong value on shift.");
//     mu_assert(List_count(list) == 0, "Wrong count after shift.");
//     return NULL;
// }

char *all_tests(){
<<<<<<< Updated upstream
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_push_pop);
=======

    s1 = strdup("hello world");
    s2 = strdup("hello world");
    s3 = strdup("hello world");


    free(s1);
    log_info("%s", s1);
    // mu_suite_start();
    // mu_run_test(test_create);
    // mu_run_test(test_push_pop(test1, test2, test3));
    // mu_run_test(test_clear);
    // mu_run_test(test_destroy);
    // mu_run_test(test_clear);
>>>>>>> Stashed changes
    // mu_run_test(test_unshift);
    // mu_run_test(test_remove);
    // mu_run_test(test_shift);
    // mu_run_test(test_destroy);
    return NULL;
}

RUN_TESTS(all_tests);