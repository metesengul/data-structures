#include <stdio.h>
#include <stdlib.h>


struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int);
void insert(struct node*, int);
void LDR(struct node*);


int main(){

	struct node* root = NULL;

	root = newNode(4);
	insert(root, 5);
	insert(root, 2);
	insert(root, 7);

	LDR(root);

}


struct node* newNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
	
	newNode->data = data; 
	newNode->left = NULL; 
	newNode->right = NULL;

	return newNode;

}

void insert(struct node* root, int data) 
{ 
    if (root == NULL)
    {
			printf("You can't insert to NULL.");
			exit(1);
    }

	struct node* current = root;
	while(1){

		if (data < current->data){
			if(current->left == NULL){
				current->left = newNode(data);
				break;
			}
			current = current->left;
		}

    else if (data > current->data){
			if(current->right == NULL){
				current->right = newNode(data);
				break;
			}
			current = current->right;
		}
	}


}


void LDR(struct node* root) 
{ 
  if (root != NULL) 
  { 
    LDR(root->left); 
    printf("%d\n", root->data); 
    LDR(root->right); 
  } 
} 
