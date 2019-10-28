#include <stdio.h>
#include "node.h"

int main() {
  struct node *list = NULL;
  printf("Printling empty list:\n");
  print_list(list);
  printf("\n");

  list = insert_front(list, "be");
  list = insert_front(list, "to");
  list = insert_front(list, "not");
  list = insert_front(list, "or");
  list = insert_front(list, "be");
  list = insert_front(list, "To");

  printf("Hamlet opening:\n");
  print_list(list);
  printf("\n");

  list = remove_data(list, "be");
  printf("Remove \"be\":\n");
  print_list(list);
  printf("\n");

  //array used to ensure comparison is not of pointer addresses
  char to[] = "To";
  list = remove_data(list, to);
  printf("Remove front of list (\"To\"):\n");
  print_list(list);
  printf("\n");

  list = remove_data(list, "to");
  printf("Remove end of list (\"to\"):\n");
  print_list(list);
  printf("\n");

  list = free_list(list);
  printf("Free list:\n");
  print_list(list);
  printf("\n");

  return 0;
}
