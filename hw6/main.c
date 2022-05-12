#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
} node_t;


node_t* allocate_node(int data){
	node_t* next_node = (node_t*)calloc(1, sizeof(node_t));
	next_node->data = data;
	next_node->next = NULL;
	return next_node;
}

void show_list(node_t* head) {
	while(head != NULL) {
		printf("[%d]->", head->data);
		head = head->next;
	}
	printf("null\n");
}

node_t* append_node(node_t* head, int new_data) {
	if(head == NULL) {
		return allocate_node(new_data);
	}
	node_t* list = head;
	while(list->next != NULL) {
		list = list->next;
	}
	list->next = allocate_node(new_data);
	return head;
}

void free_all_node(node_t* head) {
	node_t* p;
	while(head != NULL) {
		p = head;
		head = head->next;
		printf("free([%d])->", p->data);
		free(p);
	}
	printf("null\n");
}

node_t* add_node(node_t* head, int new_data) {
	node_t* new_head = allocate_node(new_data);
	new_head->next = head;
	return new_head;

}

node_t* del_node(node_t* head, int n)  {
	node_t* dummy_head = allocate_node(0);
	dummy_head->next = head;

	int count = 0;
	node_t* p = dummy_head;
	while(count != n) {
		p = p->next;
		count++;
	}
	node_t* delete_node = p->next;
	p->next = delete_node->next;
	free(delete_node);
	
	return dummy_head->next;
}


int main(void) {
  
	node_t* head = NULL;
	head = append_node(head, 0);
	show_list(head);
	head = append_node(head, 1);
	show_list(head);
	head = add_node(head, -1);
	show_list(head);
	del_node(head, 1);
	show_list(head);
	free_all_node(head);
	
	return 0;
}
