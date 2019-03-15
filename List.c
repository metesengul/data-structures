#include <stdio.h>
#include <stdlib.h>

struct node 
{ 
  int data; 
  struct node *next; 
};

struct node* newNode(int);
void insert(struct node*, int);
void display(struct node*);


int main(){

	struct node* head = NULL;
	
	head = newNode(4);
	insert(head, 34);
	insert(head, 64);
	insert(head, 14);
	
	display(head);

	return 0;
}


struct node* newNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

void insert(struct node* head, int data)
{
	if(head == NULL){
		printf("You can't insert to NULL.\n");
		exit(1);
	}

	struct node* current = head;
	while(1)
	{
		if(current->next == NULL){
			current->next = newNode(data);
			break;
		}
		current = current->next;
	}
}

void display(struct node* head)
{
	struct node* current = head;
	while(1)
	{
		printf("%d\n", current->data);
		if(current->next == NULL){
			break;
		}
		current = current->next;
	}
}
