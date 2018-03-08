#include "list.h"
#include <stdio.h> 

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
	if (head == NULL){
		return true;
	}else{
		return false;
	}
}

Node* InsertNode(Node** phead, int index, double x){

}

/*

– insert a new node *after* position index
– position of nodes starts from 1
– insert a new node as the head if index=0
– returns a pointer to the new node if insertion
is successful and null otherwise

*/