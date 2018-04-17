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
	if (queue->counter == 0){ // if counter is equal to zero: queue is empty
		return true;
	}else{
		return false;
	}
}

bool IsFull(Queue* queue){
	if (queue -> counter == queue -> maxSize){ // if counter is equal to maximum size: queue is full
		return true;
	}else{
		return false;
	}
}


bool Enqueue(Queue* queue, double x){
	if(IsFull(queue)){
		printf("Error: the queue is full.\n"); // queue can't enqueue if the queue is full
		return false;
	}
	queue -> rear = (queue -> rear + 1) % queue -> maxSize; // Circular increase index
	queue -> values[queue -> rear] = x;
	queue -> counter++; // modify counter to indicate the queue status
	return true;
}

bool Dequeue(Queue* queue, double* x){
	if(IsEmpty(queue)){ // queue can't dequeue if the queue is empty
		return false;
	}
	*x = queue -> values[queue -> front];
	queue -> front = (queue -> front + 1) % queue -> maxSize; // Circular decrease index
	queue -> counter--; // modify counter to indicate the queue status
	return true;
}

void DisplayQueue(Queue* queue){
	if(IsEmpty(queue)){
		printf("The queue is empty.\n");
	}
	for (int i = 0; i < queue -> counter; i++){
		int currentIndex = ((queue -> front + i) % (queue -> maxSize)); // use front, i and maxSize to calculate the correct index
		if (currentIndex == queue -> front){ // if the current index is the front index
			printf("front -->\t"); // print a front message
		}else{
			printf("\t\t"); // otherwise just print two tab
		}
		printf("%g", queue->values[currentIndex]); // print out the queue value according to index
		if(currentIndex == queue -> rear){ // if the current index is the rear index
			printf("\t<-- rear\n"); // print a rear message
		}else{
			printf("\n"); // otherwise just print a line break
		}
	}
}

void DestroyQueue(Queue* queue){
	free(queue->values); // free the queue values array
}
