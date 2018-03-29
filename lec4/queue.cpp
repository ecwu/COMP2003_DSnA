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