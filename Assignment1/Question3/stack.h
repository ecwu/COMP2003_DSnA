#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	char* values; // point to an array which stores elements of stack
	int top; // the index of the top element of stack
	int maxTop; // the max size of stack
} Stack;


bool CreateStack(Stack *stack, int size);

// Creates an empty stack with a capacity is size

bool IsEmpty(Stack* stack);

// Returns true if the stack is empty and false otherwise

bool IsFull(Stack* stack);

// Returns true if the stack is full and false otherwise

bool Top(Stack* stack, char* x);

// return the top element to x

bool Push(Stack* stack, char x);

/*
	Add a new element with value x to the top of the stack
	Returns true if the operation is successful and false otherwise
*/

bool Pop(Stack* stack, char* x);

/*
	Remove an element from the top of the stack
	Returns true if the operation is successful and false otherwise
	Passes the value of the top element to x
*/

void UpdateTop(Stack* stack, int number);
/*
	update the new top value
*/

void DisplayStack(Stack* stack);

/*
	Display the whole stack and noted the stack top
*/

void DestroyStack(Stack* stack);

/*
	Frees the memory occupied by the stack
*/

char* Uncompress(char* str);

// the uncompress function