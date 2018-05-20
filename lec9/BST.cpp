#include "BST.h"
#include "stdlib.h"
#include<stdio.h>

Node* insertNode(Node **proot, int x){
	if (*proot == NULL) {
		*proot = (Node *)malloc(sizeof(Node)); // create the node
		(*proot)->key = x;
		(*proot)->left = NULL;
		(*proot)->right = NULL;
		return *proot;
	}
	if ((*proot)->key == x) {
		return NULL;
	}
	if ((*proot)->key > x) { // if x is greater than key
		return insertNode(&(*proot)->left, x); // go left
	}
	else {
		return insertNode(&(*proot)->right, x); // go right
	}
}
Node* deleteNode(Node **proot, int x) {
	Node *deletingNode = findNode(*proot, x); // find the deleting node if exist
	Node *current = *proot;

	//When the root is the deleteNode
	if (current->key == x) {
		if (current->right != NULL) {
			current = current->right; // find the minimum in the right subtree
			if (current->left != NULL) {
				while (current->left->left != NULL) {
					current = current->left;
				}
				*proot = current->left; // swap
				current->left = NULL;
				current = *proot;
				current->left = deletingNode->left;
				current->right = deletingNode->right;
				return deletingNode;
			}
			*proot = current;
			current->left = deletingNode->left;
			return deletingNode;
		}
		*proot = current->left;
		return deletingNode;
	}

	while (true) {
		// if the node have zero child
		if (current->left != NULL && current->right != NULL) {
			if (current->left->key != x && current->right->key != x) {
				if (current->key > x) {
					current = current->left;
				}
				else {
					current = current->right;
				}
				continue;
			}
		}
		// if the node have one child (left)
		else if (current->left != NULL && current->right == NULL) {
			if (current->left->key != x) {
				current = current->left;
				continue;
			}
		}
		// if the node have one child (right)
		else if (current->left == NULL && current->right != NULL) {
			if (current->right->key != x) {
				current = current->right;
				continue;
			}
		}
		break;
	}

	Node *minNode; // the minimum node on the right subtree
	if (deletingNode->right != NULL) {
		minNode = deletingNode->right;
		if (minNode->left != NULL) {
			while (minNode->left->left != NULL) { // keep move left and go to minimum node
				minNode = minNode->left;
			}
			// swap the delete node with the minimum node
			if (current->key > x) {
				current->left = minNode->left;
				minNode->left = NULL;
				minNode = current->left;
			}
			else {
				current->right = minNode->left;
				minNode->left = NULL;
				minNode = current->right;
			}
			minNode->left = deletingNode->left;
			minNode->right = deletingNode->right;
			return deletingNode;
		}

		if (current->key > x) {
			current->left = minNode;
		}
		else {
			current->right = minNode;
		}
		minNode->left = deletingNode->left;
		return deletingNode;
	}
	if (current->key > x) { // if x smaller than key, move left
		current->left = current->left->left;
	}
	else { // if x greater than key, move right
		current->right = current->right->left;
	}
	return deletingNode;
}
Node* findNode(Node *root, int x){
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