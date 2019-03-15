#include <stdio.h>
#include <stdlib.h>


#define MAXQUEUE 5

struct queue {
    int head;
		int rear;
    int items[MAXQUEUE];
};

void enqueue(struct queue* q, int data);
int dequeue(struct queue* q);
void display(struct queue* q);


int main ()
{  
	struct queue q;

	q.head = -1;
	q.rear = -1;

	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);

	dequeue(&q);
	dequeue(&q);

	display(&q);

	return 0;
}


void enqueue(struct queue* q, int data)
{

	if(q->head - q->rear == 1 || (q->rear == MAXQUEUE - 1 && q->head == 0))
	{ 
		printf("Queue is full.\n\n");
		exit(1);
	}

	if(q->head == -1)
	{
		q->head = 0;
	}

	q->rear = (q->rear + 1) % MAXQUEUE;
	q->items[q->rear] = data;
}


int dequeue(struct queue* q)
{
		if (q->head == -1)
		{
			printf("Queue is empty.\n\n");
			exit(1);
		}
		
		int removedElement = q->items[q->head];
		if(q->head == q->rear){
			q->head = -1;
			q->rear = -1;
    }
		else{
			q->head = (q->head + 1) % MAXQUEUE;
		}

    return removedElement;
}

void display(struct queue* q)
{
	int i = q->rear + 1;

	printf ("Queue:\n");
	while(1)
	{
		if(i == 0){
			i = MAXQUEUE - 1;
		}
		else{
			i--;
		}
		printf("%d\n", q->items[i]);

		if (i == q->head)
		{
			break;
		}
	}
}