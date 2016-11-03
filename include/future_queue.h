/* QUEUE DATA STRUCTURE */

typedef struct queue
{
	int capacity;
	int size;
	int front;
	int rear;
	pid32 *process;

}queue;

/* CREATE A QUEUE WITH ITS MAX SIZE AS AN ARGUMENT */

queue * createqueue	(int maxElements)
{
	queue *q;
	q = (queue*)malloc(sizeof(queue);
	q->process=(int *)malloc(sizeof(int)*maxElements);
	q->size = 0;
        q->capacity = maxElements;
        q->front = 0;
        q->rear = -1;
	return q;
}

/* REMOVE ELEMENT FROM THE FRONT */

pid32 dequeue (queue *q)
{
	if(q->size==0)
		{
			printf("\nQueue is empty\n");
			return 0;
		}

	else
		{
			queue *q_temp = q->front;
			pid32 p = temp->pid
			q->size--;
			q->front++;
			if(q->front==q->capacity)
				q->front=0;
		}
	return p ;
}


/* ADD A NEW ELEMENT AT THE REAR */

void enqueue (queue *q , pid32 p)
{
	if(q->size==q->capacity)
	{
		printf("\nQueue is full\n");
		exit(0);
	}

	else
	{
		q->size++;
		q->rear=q->rear+1;
		if(q->rear==q->capacity)
			q->rear=0;
		q->process[q->rear]=p;
	}
	return;
}



/* OBTAIN FOREMOST ELEMENT */


int front(queue *q)
{
	if(q->size=0)
	{
		printf("\nQueue is empty\n");
		exit(0);
	}

	return q->elements[q->front];	
}

/* CHECK WHETHER QUEUE IS EMPTY */

int empty (queue *q)
{
	if(front>rear) {
		printf("Queue is empty");
		return 1;
	}
	
	printf("Queue has : %d processes" , queue->size);
}
	 


