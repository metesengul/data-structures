#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10


struct stack
{   
  int arr[MAXSIZE];
  int top;
};

void push(struct stack*, int);
int pop(struct stack*);
void display(struct stack*);

int main()
{   
  struct stack s;
  s.top = -1;

	push(&s, 5);
	push(&s, 45);
	display(&s);

}

void push(struct stack* stack, int data)
{   
  if (stack->top == (MAXSIZE - 1))
  {
		printf("Stack is full.\n");
    exit(1);
  }
  else
  { 
    (stack->top)++;
    stack->arr[stack->top] = data;
  }
  return;
}

int pop(struct stack* stack)
{ 
	
  if (stack->top == - 1)
  {   
    printf("Stack is empty.\n");
    exit(1);
  }

	int removedElement = stack->arr[stack->top];
	stack->top = stack->top - 1;
  
  return(removedElement);
}

void display(struct stack* stack)
{   
	for (int i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->arr[i]);
	}
}
