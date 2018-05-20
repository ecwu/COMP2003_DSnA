#include "AVL.h"
#include "stdlib.h"
#include "stdio.h"

Node* insertNode(Node **proot, int x) {
	Node *newNode;
	if ((*proot) == NULL) {
		*proot = (Node *)malloc(sizeof(Node)); // create the node
		(*proot)->left = NULL;
		(*proot)->right = NULL;
		(*proot)->key = x;
		(*proot)->height = 0;
		return *proot;
	}
	if ((*proot)->key == x) {
		return NULL;
	}
	if ((*proot)->key > x) {
		newNode = insertNode(&(*proot)->left, x); // move left
	}
	else {
		newNode = insertNode(&(*proot)->right, x); // move right
	}
	UpdateHeight(proot); // update node's height
	Rebalance(proot); // rebalance the tree
	return newNode;
}

Node* deleteNode(Node **proot, int x) {
	Node *matchNode;
	if (*proot == NULL) {
		return NULL;
	}
	if ((*proot)->key > x) { // find the node should delect
		matchNode = deleteNode(&(*proot)->left, x);
	}
	else if ((*proot)->key < x) {
		matchNode = deleteNode(&(*proot)->right, x);
	}
	else {
		matchNode = deleteRoot(&(*proot));
	}
	UpdateHeight(proot); // update node's height
	Rebalance(proot); // rebalance the tree
	return matchNode;
}

Node* deleteRoot(Node **proot) {
	Node *currNode = *proot;
	if ((*proot)->left == NULL) {
		*proot = (*proot)->right;
		return currNode;
	}
	if ((*proot)->right == NULL) {
		*proot = (*proot)->left;
		return currNode;
	}
	Node *minNode = deleteMin(&(*proot)->right); // replace the min with the root
	minNode->left = (*proot)->left;
	minNode->right = (*proot)->right;
	*proot = minNode;
	return currNode;
}

Node* deleteMin(Node **proot) { // find the min on the right
	Node *minNode;
	if ((*proot)->left == NULL) {
		minNode = (*proot);
		*proot = (*proot)->right;
		return minNode;
	}
	minNode = deleteMin(&(*proot)->left); 
	UpdateHeight(proot);//Update height
	Rebalance(proot);//Balance the tree
	return minNode;
}

void Rebalance(Node **proot) {
	// do the rotate according to the tree status
	switch (Balanced(*proot)) {
	case 1:
		rightRotate(*proot);
		break;
	case 2:
		leftRotate(*proot);
		break;
	case 3:
		leftRotate((*proot)->left); // pass the different node to implement the double rotation
		rightRotate(*proot);
		break;
	case 4:
		rightRotate((*proot)->right); // pass the different node to implement the double rotation
		leftRotate(*proot);
		break;
	}
}

void leftRotate(Node *root) {
	Node *newHead = root->right;
	Node *oldHead;
	oldHead = (Node *)malloc(sizeof(Node));
	oldHead->left = NULL;
	oldHead->right = NULL;
	oldHead->key = root->key;
	oldHead->height = 0;
	oldHead->left = root->left;
	UpdateHeight(&oldHead);
	oldHead->right = newHead->left;
	root->left = oldHead;
	root->right = newHead->right;
	root->key = newHead->key;
	UpdateHeight(&root);
	free(newHead);
}

void rightRotate(Node *root) {
	Node *newHead = root->left;
	Node *oldHead;
	oldHead = (Node *)malloc(sizeof(Node));
	oldHead->left = NULL;
	oldHead->right = NULL;
	oldHead->key = root->key;
	oldHead->height = 0;
	oldHead->right = root->right;
	UpdateHeight(&oldHead);
	oldHead->left = newHead->right;
	root->right = oldHead;
	root->left = newHead->left;
	root->key = newHead->key;
	UpdateHeight(&root);
	free(newHead);
}

void UpdateHeight(Node **proot) {
	if (*proot != NULL) {
		if ((*proot)->left == NULL && (*proot)->right == NULL) { // leaf
			(*proot)->height = 0;
		}
		else if ((*proot)->left == NULL) {
			(*proot)->height = (*proot)->right->height + 1;
		}
		else if ((*proot)->right == NULL) {
			(*proot)->height = (*proot)->left->height + 1;
		}
		else {
			if ((*proot)->left->height > (*proot)->right->height) {
				(*proot)->height = (*proot)->left->height + 1;
			}
			else {
				(*proot)->height = (*proot)->right->height + 1;
			}
		}
	}
}

int Balanced(Node *root) {
	if (root->height == 2 && root->right == NULL) {
		if (root->left->left == NULL) {
			return 3; // double rotation
		}
		return 1; // right rotation
	}
	if (root->height == 2 && root->left == NULL) {
		if (root->right->right == NULL) {
			return 4; // double rotation
		}
		return 2; // left rotation
	}
	if (root->left != NULL && root->height - root->left->height == 3) {
		if (root->right->right->height > root->right->left->height) {
			return 2; // left rotation
		}
		return 4; // double rotation
	}
	if (root->right != NULL && root->height - root->right->height == 3) {
		if (root->left->left->height > root->left->right->height) {
			return 1; // right rotation
		}
		return 3; // double rotation
	}
	return -1; // error
}

Node* findNode(Node *root, int x){
	// same as BST
	if (root == NULL) {
		return NULL;
	}
	if (root->key == x) { // if found, return
		return root;
	}
	if (root->key > x) {
		return findNode(root->left, x); // if smaller, move left
	}
	else {
		return findNode(root->right, x); // if greater, move right
	}
}

void destroyTree(Node *root){
	// same as BST
	if (root == NULL) {
		return;
	}
	if (root->left != NULL) {
		destroyTree(root->left); // if not empty, destroy
	}
	if (root->right != NULL) {
		destroyTree(root->right);
	}
	free(root); // if is the leaf, free
}