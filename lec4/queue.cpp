#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

bool CreateQueue(Queue *queue, int size){
	if (size <= 0){ // size of a queue must greater than 0
		return false;
	}
	// allocate the memory space and init the queue
	queue -> values = (double*)malloc(sizeof(double)*size);
	queue -> front = 0;
	queue -> rear = -1;
	queue -> counter = 0;
	queue -> maxSize = size;
	return true;
}

bool IsEmpty(Queue* queue){
	if (queue->counter == 0){
		return true;
	}else{
		return false;
	}
}

bool IsFull(Queue* queue){
	if (queue -> counter == queue -> maxSize){
		return true;
	}else{
		return false;
	}
}


bool Enqueue(Queue* queue, double x){
	if(IsFull(queue)){
		printf("Error: the queue is full.\n");
		return false;
	}
	queue -> rear = (queue -> rear + 1) % queue -> maxSize;
	queue -> values[queue -> rear] = x;
	queue -> counter++;
	return true;
}bool Dequeue(Queue* queue, double* x){	if(IsEmpty(queue)){		return false;	}	*x = queue -> values[queue -> front];	queue -> front = (queue -> front + 1) % queue -> maxSize;	queue -> counter--;	return true;}void DisplayQueue(Queue* queue){	if(IsEmpty(queue)){		printf("The queue is empty.\n");	}	for (int i = 0; i < queue -> counter; i++){		int currentIndex = ((queue -> front + i) % (queue -> maxSize));		if (currentIndex == queue -> front){			printf("front -->\t");		}else{			printf("\t\t");		}		printf("%g", queue->values[currentIndex]);		if(currentIndex == queue -> rear){			printf("\t<-- rear\n");		}else{			printf("\n");		}	}}void DestroyQueue(Queue* queue){	free(queue->values);}