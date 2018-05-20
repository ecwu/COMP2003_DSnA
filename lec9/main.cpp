#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void main() 
{
  Node * root = NULL;    
  
  printf("\nAfter inserting key 10..\n");
  insertNode(&root,10);
  printTree(root);

  printf("\nAfter inserting key 5..\n");
  insertNode(&root,5);
  printTree(root);

  printf("\nAfter inserting key 15..\n");
  insertNode(&root,15);
  printTree(root);

  printf("\nAfter inserting elements 9, 13..\n");
  insertNode(&root,9);
  insertNode(&root,13);
  printTree(root);

  printf("\nAfter inserting elements 2, 6, 12, 14, ..\n");
  insertNode(&root,2);
  insertNode(&root,6);
  insertNode(&root,12);
  insertNode(&root,14);
  printTree(root);

  
  printf("\n\nAfter deleting a node (14) with no child..\n");
  free(deleteNode(&root,14));
  printTree(root);

  printf("\n\nAfter deleting a node (13) with left child..\n");
  free(deleteNode(&root,13));
  printTree(root);

  printf("\n\nAfter deleting a node (5) with left and right children..\n");
  free(deleteNode(&root,15));
  printTree(root);

  printf("\n\nAfter deleting a node (10) with left and right children..\n");
  free(deleteNode(&root,10));
  printTree(root);

  destroyTree(root);
}