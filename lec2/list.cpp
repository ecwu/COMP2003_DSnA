#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
	Node *head = 0;
	for(int i=0; i<5; i++)
		InsertNode(&head, i, i);
	DisplayList(head);
	for(int i=0; i<5; i++)
		InsertNode(&head, 0, i);
	DisplayList(head);
	for(int i=0; i<7; i+=2){
		int idx = FindNode(head, i);
		if(idx>0)
			printf("%d is at position %d.\n", i, idx);
		else
			printf("%d is not in the list.\n", i);
	}
	DeleteNode(&head, 0);
	DisplayList(head);
	DestroyList(head);
}

bool IsEmpty(Node* head){
	if (head == NULL){ // check the existence of the linked list
		return true;
	}else{
		return false;
	}
}

Node* InsertNode(Node** phead, int index, double x){
	if (index < 0){
		return NULL; // if the index is invalid, return null
	}
	Node *pCurrent = *phead;
	int currentIndex = 1;
	while (currentIndex < index && pCurrent){
		if (pCurrent->next == NULL){
			return NULL; // if the index is larger than the tail's index, return null
		}
		pCurrent = pCurrent->next;
		currentIndex++;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	if (index == 0){ // insert at the head of the linked list
		newNode->next = *phead;
		*phead = newNode; // Modify the original phead and point it to the new inserted node
	}else{
		newNode->next = pCurrent->next; // insert the node after that index node
		pCurrent->next = newNode;
		// no need to modify the pHead
	}
	return newNode;
}

int FindNode(Node* head, double x){
	Node *pCurrent = head;
	int NodeIndex = 1;
	while(pCurrent->data != x){
		if(pCurrent->next == NULL){
			return 0; // Can't find a valid Node
		}
		pCurrent = pCurrent->next;
		NodeIndex++;
	}
	return NodeIndex;
}

int DeleteNode(Node **phead, double x){
	Node *pCurrent = *phead;
	Node *pDelete = *phead;
	int NodeIndex = 1;
	if (pCurrent->data == x){ // if the first node is match x
		*phead = pCurrent->next;
		free(pCurrent);
		return NodeIndex;
	}else{
		while (pCurrent->next->data != x){ // find the node before the delete node
			if (pCurrent->next->next == NULL){
				return 0; // Can't find a valid Node
			}
			pCurrent = pCurrent->next;
			NodeIndex++;
		}
		pDelete = pCurrent->next;
		pCurrent->next = pCurrent->next->next;
		free(pDelete); // delete the node
		return NodeIndex + 1;
	}
}

void DisplayList(Node *head){
	if (IsEmpty(head)){
		printf("Empty Linked list\n");
		return;
	}
	Node *pCurrent = head;
	while(pCurrent->next != NULL){ // print every node in the linked list, until meet a node which its next is null
		printf("%lf\n", pCurrent->data);
		pCurrent = pCurrent->next; 
	}
	printf("%lf\n", pCurrent->data); // print the last node
}

void DestroyList(Node *head){ // free up the memory space
	if (IsEmpty(head)){
		printf("Empty Linked list\n");
		return;
	}
	Node *pCurrent = head;
	while (head->next != NULL){
		head = pCurrent->next;
		free(pCurrent);
		pCurrent = head;
	}
	free(pCurrent);
}
