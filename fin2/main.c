#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *next;
} LinkedList;

LinkedList *allocate_node(int data) {
  LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
  node->data = data;
  node->next = NULL;
  return node;
}

void show_list(LinkedList *list) {
  LinkedList *temp = list;
  while (temp != NULL) {
    printf("[%c]->", temp->data);
    temp = temp->next;
  };
  printf("->NULL\n");
}

LinkedList *append_node(LinkedList *list, int new_data) {
  LinkedList *node = allocate_node(new_data);
  node->data = new_data;
  node->next = NULL;
  if (list == NULL) {
    list = node;
  } else {
    LinkedList *lastNode = list;
    while (lastNode->next != NULL) lastNode = lastNode->next;
    lastNode->next = node;
  };
  return list;
}

LinkedList *reverse_node(LinkedList *list) {
  LinkedList *prev = NULL;
  LinkedList *current = list;
  LinkedList *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main() {
  LinkedList* head = NULL;
  head = append_node(head, 'A');
  head = append_node(head, 'B');
  head = append_node(head, 'C');
  head = append_node(head, 'D');
  head = append_node(head, 'E');
  show_list(head);
  head = reverse_node(head);
  show_list(head);
  return 0;
}
