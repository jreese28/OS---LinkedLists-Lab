// list/list.c
// 
// Implementation for linked list.
//
// J'nya Reese
//jnya.reese@bison.howard.edu

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc(){
  list_t *l = malloc(sizeof(list_t));
  return l;
}

node_t *node_alloc(elem val){
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = val;
  return new_node;
}

void list_free(list_t *l){
  while(l->head != NULL){
    node_t *temp = l->head;
    l->head = l->head->next;
    free(temp);
  };
}

void list_print(list_t *l){
  node_t *current = l->head;
  while(current != NULL){
    printf("%d->", current->value);
    current = current->next;
  };
}

int list_length(list_t *l){
  node_t *current = l->head;
  int count = 0;
  while(l->head != NULL){
    count += 1;
    l->head = l->head->next;
  }
  l->head = current;
  return count;
}

void list_add_to_back(list_t *l, elem value){
  node_t *current = l->head;
  while(l->head->next != NULL){
    l->head = l->head->next;
  };
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  l->head->next = new_node;

  l->head = current;
  return;
}

void list_add_to_front(list_t *l, elem value){
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value,int index){
  node_t *current = l->head;
  
  if(index == 0){
    list_add_to_front(l, value);
    return;
  }

  if(index == list_length(l) - 1){
    list_add_to_back(l, value);
    return;
  }

  if(index >= list_length(l)){
    printf("Index too large");
    return;
  }

  while(index != 1){
    index -= 1;
    l->head = l->head->next;
  }

  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head->next;
  l->head->next = new_node;
  l->head = current;  
}

elem list_remove_from_back(list_t *l){
  node_t *current = l->head;

  if(list_length(l) == 1){
    list_remove_from_front(l);
    return 0;
  }

  while(l->head->next->next != NULL){
    l->head = l->head->next;;
  }
  free(l->head->next);
  l->head->next = NULL;
  l->head = current;
  return -1;
}

elem list_remove_from_front(list_t *l){
  node_t *temp = l->head;
  l->head = l->head->next;
  free(temp);
  return l->head->value;
}

elem list_remove_at_index(list_t *l, int index){
  node_t *current = l->head;

  while(index != 1){
    index -= 1;
    l->head = l->head->next;
  }

  node_t *temp = l->head->next;
  l->head->next = l->head->next->next;
  l->head = current;
  free(temp);
  return -1;
}

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head;
  while(l->head != NULL){
    if(l->head->value != value){
      l->head = l->head->next;
    } else {
      l->head = current;
      return true;
    }
  }
  l->head = current;
  return false; 
}

elem list_get_elem_at(list_t *l, int index){
  node_t *current = l->head;

  while(l->head != NULL){
    if(index != 0){
      l->head = l->head->next;
    }
    else{
      int temp = l->head->value;
      l->head = current;
      return temp;
    }
    index -= 1;
  }
  l->head =current;
  return -1;
}

int list_get_index_of(list_t *l, elem value){
  node_t *current = l -> head;
  int count = 0;

  while(l->head != NULL){
    if(l->head->value != value){
      l->head = l ->head->next;
      count += 1;
    }
    else{
      l->head = current;
      return count;
    }
  }
  l->head = current;
  return -1;
}