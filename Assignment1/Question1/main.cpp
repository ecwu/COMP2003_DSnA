#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
	Node *head = 0;
	// 1 --> 2 --> 2 --> 4 --> 6 --> 6 Example
	InsertNode(&head, 0, 1);
	InsertNode(&head, 1, 2);
	InsertNode(&head, 2, 2);
	InsertNode(&head, 3, 4);
	InsertNode(&head, 4, 6);
	InsertNode(&head, 5, 6);
	DisplayList(head);
	printf("------\n");
	RemoveDuplicates(&head);
	DisplayList(head);
	printf("------\n");
	DeleteNode(&head, 1);
	DeleteNode(&head, 4);// delete all the rest node
	DisplayList(head);
	printf("------\n");
	// Null example
	RemoveDuplicates(&head); 
	DisplayList(head);
	printf("------\n");
	// 6 --> 6 --> 6 --> 7 --> 7 Example
	InsertNode(&head, 0, 6);
	InsertNode(&head, 1, 6);
	InsertNode(&head, 2, 6);
	InsertNode(&head, 3, 7);
	InsertNode(&head, 4, 7);
	DisplayList(head);
	printf("------\n");
	RemoveDuplicates(&head);
	DisplayList(head);
	printf("------\n");
	DestroyList(head);
}