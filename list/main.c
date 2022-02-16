#include <stdio.h>
#include "list.h"

int main(){
  elem val;
  printf("Test for linked list implementation\n");

  list_t *mylist = list_alloc();
  list_print(mylist);

  printf("Inserting to front: 5\n");
  list_add_to_front(mylist, 5);

  printf("Inserting at index 0: 35\n");
  list_add_at_index(mylist, 35, 0);

  printf("Inserting to back: 20\n");
  list_add_to_back(mylist, 20);

  printf("Inserting to front: 10\n");
  list_add_to_front(mylist, 10);

  printf("Inserting at index 2: 40\n");
  list_add_at_index(mylist, 40, 2);

  printf("Inserting to back: 15\n");
  list_add_to_back(mylist, 15);

  printf("Inserting to front: 45\n");
  list_add_to_front(mylist, 40);

  printf("Inserting at index 4: 25\n");
  list_add_at_index(mylist, 25, 4);

  printf("Inserting to back: 30\n");
  list_add_to_back(mylist, 30);

  printf("Current list: ");
  list_print(mylist);
  printf("\n");

  printf("Removing from front: ");
  list_remove_from_front(mylist);
  list_print(mylist);
  printf("\n");

  printf("Removing from index 3: ");
  list_remove_at_index(mylist, 3);
  list_print(mylist);
  printf("\n");

  printf("Removing from back: ");
  list_remove_from_back(mylist);
  list_print(mylist);
  printf("\n");

  val = list_length(mylist);
  printf("Length of list is: %d", val);
  printf("\n");

  bool x = list_is_in(mylist, 20);
  printf("20 is in list: ");

  if(x == 1){
    printf("True");
  }
  else{
    printf("False");
  }
  printf("\n");

  val = list_get_elem_at(mylist, 4);
  printf("Element at index 4: %d", val);
  printf("\n");

  val = list_get_index_of(mylist, 5);
  printf("Index of 5: %d", val);
  printf("\n");

  return 0;  
}