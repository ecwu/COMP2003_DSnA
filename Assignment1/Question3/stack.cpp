#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

bool CreateStack(Stack *stack, int size){
	if (size <= 0){
		return false; // if the stack's size is small or equal to zero, this is not gonna happen.
	}
	stack -> values = (char*)malloc(sizeof(char)*size);
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

bool Top(Stack* stack, char* x){
	if(IsEmpty(stack)){ // Stack must has element(s) to find the top elements
		return false;
	}
	*x = stack -> values[stack -> top];
	return true;
}

bool Push(Stack* stack, char x){
	if(IsFull(stack)){ // Stack must be not empty to push a new element
		return false;
	}
	stack -> values[++stack -> top] = x; // stack->top increase first then index
	stack -> values[stack->top + 1] = '\0';
	return true;
}

bool Pop(Stack* stack, char* x){
	if(IsEmpty(stack)){ // Stack must has element(s) to pop the top elements
		return false;
	}
	*x = stack -> values[stack -> top--]; // stack->top index first then decrease
	stack->values[stack->top + 1] = '\0';
	return true;
}

void UpdateTop(Stack* stack, int number) {
	stack->top += number; // add a number to top
}


void DisplayStack(Stack* stack){
	for (int i = stack -> top; i >= 0; i--){ // print from the end of the array (Stack top) to the head of the array (Stack Bottom)
 		if (i == stack -> top){
			printf("top -->\t"); // print a indicator to show this is the top
		}else{
			printf("\t");
		}
		printf("|\t%c\t|\n", stack->values[i]);
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

char* Uncompress(char* str) {
	if (str == NULL) { // if the input is NULL
		return NULL;
	}
	int strLength = strlen(str);
	Stack mainStack;
	Stack subStack;
	char temp;
	char topTemp;
	char finalResult[10000] = "\0"; // string use to store the final result


	if (strLength <= 0) {
		return str;
	}
	CreateStack(&mainStack, 10000);
	CreateStack(&subStack, 10000);

	for (int i = 0; i < strLength; i++) { // from the begin to the end
		if (str[i] != ']') { // push every char into mainStack until meet ']'
			Push(&mainStack, str[i]);
		}
		else {
			do {
				Pop(&mainStack, &temp); // then pop every char into subStack until meet '['
				Push(&subStack, temp);
				Top(&subStack, &topTemp);
			} while (topTemp != '[');
			Pop(&subStack, &temp); // remove the latest '['
			_strrev(subStack.values); // inverse the string (provide in string.h)
			int digits = 1;
			int ktimes = 0;
			Top(&mainStack, &topTemp);
			// get the compress number k (ktimes)
			while (topTemp >= 48 && topTemp <= 57 && !IsEmpty(&mainStack)) { // if the next char is a number & stack is not empty
				Pop(&mainStack, &temp);
				ktimes += (int)((temp - '0') * pow(10, digits - 1));
				digits++;
				Top(&mainStack, &topTemp);
			}
			for (int i = 0; i < ktimes; i++) { // repeat x time (decompress)
				int subLength = strlen(subStack.values);
				strcat(mainStack.values, subStack.values);
				UpdateTop(&mainStack, subLength); // also have to add string's length to mainStack (tp indicate the top)
			}
			while (!IsEmpty(&subStack)) {// clean the subStack
				Pop(&subStack, &temp);
			}
		}
	}
	strcpy(finalResult, mainStack.values); // copy the result to the return string

	DestroyStack(&mainStack); // free the memory
	DestroyStack(&subStack);

	return finalResult;
}