#ifndef __NODE_GUARD
#define __NODE_GUARD

struct node {
  char data[16];
  struct node *next;
};

void print_list(struct node *list);

//characters beyond index 14 will be ignored
struct node * insert_front(struct node *list, char *data);

struct node * free_list(struct node *list);

//if strlen(data) > 15 this will not remove anything
struct node * remove_data(struct node *front, char *data);

#endif //__NODE_GUARD
