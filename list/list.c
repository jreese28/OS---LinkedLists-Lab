// list/list.c
// 
// Implementation for linked list.
//
// J'nya Reese
//jnya.reese@bison.howard.edu

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() {
    node_ * head == NULL;
    head = (node_t *) malloc(sizeof(node_t));

    head -> value = 0;
    head -> next = 0;
    list_t * new_list = NULL;
    new_list = (list_t *) malloc(sizeof(list_t));
    new_list -> head = head;
    return new_list;
    }
void list_free(list_t *l) {}

void list_print(list_t *l) {
    node_t * current = l -> head;
    while(current != NULL){
        printf("%d\n", current -> value);
        current = current -> next;
    }
}
int list_length(list_t *l) {
    int count = 0;
    node_t * current = l -> head;
    while(current != NULL){
        count++;
        current = current -> next;
    }
    printf("List length: %d\n", count);
    return count;
}

void list_add_to_back(list_t *l, elem value) {
    node_t * current = l -> head;
    while(current -> next != NULL){
        current = current -> next;
    }
    current -> next = (node_t *) malloc(sizeof(node_t));
    current -> next -> value = value;
    current -> next -> next = NULL;
}

void list_add_to_front(list_t *l, elem value) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node -> value =  value;
    new_node -> next = l -> head;
    l -> head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {}

elem list_remove_from_back(list_t *l) {
    int returnVal = 0;

    if(l -> head -> next == NULL){
        returnVal = l -> head -> value;
        free(l -> head);
        printf("Removed value: %d\n", returnVal);
        return returnVal;
    }
    returnVal = current -> next -> value;
    free(current -> next);
    current -> next = NULL;
    printf("Removed value: %d\n", returnVal);
    return returnVal;
}

elem list_remove_from_front(list_t *l) {
    int returnVal = -1;
    node_t * next_node = NULL;
    if(l -> head == NULL){
        return -1;
    }
    next_node = (l -> head) -> next
    returnVal = (l -> head) -> value;
    free(l -> head);
    l -> head = next_node;
    printf("Removed value: %d\n", returnVal);
    returnVal
}

elem list_remove_at_index(list_t *l, int index) {
    int i = 0;
    int returnVal = -1;
    list_t * current = l -> head ;
    list_t * temp_node = NULL;

    if(index == 0){
        return pop(head);
    }
    for(i = 0; i < index - 1; i++){
        if(current -> next == NULL){
            return -1;
        }
        current = current -> next
    }
    temp_node = current -> next;
    returnVal = temp_node -> value;
    current -> next = temp_node -> next;
    free(temp_node);
    return returnVal;
}

/*bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; } */

