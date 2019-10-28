#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_list(struct node *list) {
  printf("[ ");
  while(list != NULL) {
    printf("\"%s\", ", list->data);
    list = list->next;
  }
  printf("]");
}


//characters beyond index 14 will be ignored

struct node * insert_front(struct node *list, char *data) {
  struct node *front = calloc(1, sizeof(struct node));
  front->next = list;
  strncpy(front->data, data, sizeof front->data);
  return front;
}


struct node * free_list(struct node *list) {
  while(list != NULL) {
    struct node *curr = list;
    list = list->next;
    free(curr);
  }
  return NULL;
}

//if strlen(data) > 15 this will not remove anything

struct node * remove_data(struct node *front, char *data) {
  struct node *ret = front;
  struct node *behind = NULL;
  while(front != NULL) {
    if(strncmp(front->data, data, sizeof front->data) == 0) {
      struct node *del = front;
      front = front->next;
      free(del);
      if(behind != NULL) {
        behind->next = front;
      }
      else {
        ret = front;
      }
      continue;
    }
    behind = front;
    front = front->next;
  }
  return ret;
}
