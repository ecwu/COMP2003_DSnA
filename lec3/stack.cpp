#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

bool CreateStack(Stack *stack, int size){
	if (size <= 0){
		return false; // if the stack's size is small or equal to zero, this is not gonna happen.
	}
	stack -> values = (double*)malloc(sizeof(double)*size);
	stack -> top = -1; // index start from 0
	stack -> maxTop = size - 1; // size as index will lead to memory leak
	return true; // successful create the stack
}

bool IsEmpty(Stack* stack){
	if (stack -> top < 0){ // the index of the top element of stack is less than 0 (no element exist)
		return true;
	}else{
		return false;
	}
}

bool IsFull(Stack* stack){
	if (stack -> top == stack -> maxTop){ // the index of the top element of stack is equal to the max size of stack
		return true;
	}else{
		return false;
	}
}

bool Top(Stack* stack, double* x){
	if(IsEmpty(stack)){ // Stack must has element(s) to find the top elements
		return false;
	}
	*x = stack -> values[stack -> top];
	return true;
}

bool Push(Stack* stack, double x){
	if(IsFull(stack)){ // Stack must be not empty to push a new element
		return false;
	}
	stack -> values[++stack -> top] = x; // stack->top increase first then index
	return true;
}

bool Pop(Stack* stack, double* x){
	if(IsEmpty(stack)){ // Stack must has element(s) to pop the top elements
		return false;
	}
	*x = stack -> values[stack -> top--]; // stack->top index first then decrease
	return true;
}


void DisplayStack(Stack* stack){
	for (int i = stack -> top; i >= 0; i--){ // print from the end of the array (Stack top) to the head of the array (Stack Bottom)
 		if (i == stack -> top){
			printf("top -->\t"); // print a indicator to show this is the top
		}else{
			printf("\t");
		}
		printf("|\t%g\t|\n", stack->values[i]);
	}
	if (stack -> top < 0){
		printf("top -->\t|---------------|\n");
	}else{
		printf("\t|---------------|\n");
	}
}

void DestroyStack(Stack* stack){
	free(stack -> values);
	stack -> top = -1; // reset the stack top to -1 (empty)
}
