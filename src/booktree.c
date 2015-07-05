#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "books.h"
#include "booktree.h"

struct TreeNode *new_tree_node(unsigned long ISBN, char *author, char *title) {
	//Creating and allocating the new TreeNode
	struct TreeNode *new_tree_node;
	new_tree_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));

	//Creating the book
	struct Book *new_Book = newBook(ISBN, author, title); //No need to malloc as new_Book() already does that.

	new_tree_node->book = new_Book;

	new_tree_node->left = NULL;
	new_tree_node->right = NULL;

	*new_tree_node->key = new_tree_node->book->ISBN;

	return new_tree_node;
}

struct TreeNode *bst_search(struct TreeNode *tree_node, unsigned long key) {
	if (*tree_node->key == key) {
		//BASE CASE: If the current nodes Key equals the searched key:
		return tree_node;

	} else if (key < *tree_node->key) {
		//If the seached key is SMALLER than the current node ones
		if (tree_node->left != NULL)
			return bst_search(tree_node->left, key); //Resurses to the left node
		else
			return 0; //Value not found
	}

	else {
		//If the searched key is LARGER than the current node ones
		if (tree_node->right != NULL)
			return bst_search(tree_node->right, key); //Recurses to the right node
		else
			return 0; //Value not found
	}
}

void bst_insert(struct TreeNode *tree_node, struct TreeNode *new_node) {
	if (*new_node->key < *tree_node->key) {
		//If the key is smaller -> insert left
		//Check whether you have to recurse, or whether there is no node anymore
		if (tree_node->left == NULL) {
			//There is no left node yet
			tree_node->left = new_node;
			return;
		} else
			bst_insert(tree_node->left, new_node); //There is a node -> pass it on
	}

	else {
		//The key is larger -> right
		//Check whether you have to recurse, or whether there is no node anymore
		if (tree_node->right == NULL) {
			//There is no left node yet
			tree_node->right = new_node;
			return;
		} else
			bst_insert(tree_node->right, new_node); //There is a node -> pass it on
	}
}

void bst_clear(struct TreeNode *tree_node) {
	if (tree_node->left == NULL && tree_node->right == NULL) {
		//There are no children - free the book and the node itself
		destroyBook(tree_node->book);

		tree_node->key = NULL;

		free((void*) tree_node);
		return;
	}

	if (tree_node->left != NULL)
		bst_clear(tree_node->left); //There is a left child, so go on with left
	else
		bst_clear(tree_node->right); //There still is a right child, so go on on right
}

void printData(struct TreeNode *tree_node) {
	printf("ISBN:\t\t%lu\n", *tree_node->key); //Prints the ISBN
	printf("Author:\t\t%s\n", tree_node->book->author_name); //Author
	printf("Name:\t\t%s\n\n", tree_node->book->book_title); //Title
	return;
}

void preorderPrint(struct TreeNode *tree_node) {
	//Prints the current node
	printData(tree_node);

	if (tree_node->left != NULL) {
		//There is a left node, so go on with it
		preorderPrint(tree_node->left);
	} else if (tree_node->right != NULL) {
		//There is a right node, so go on with it
		preorderPrint(tree_node->right);
	} else
		return; //Both left and right are empty - BASE STATEMENT
}

void inorderPrint(struct TreeNode *tree_node) {
	if (tree_node->left != NULL) {
		//There is a left node, so go on with it
		inorderPrint(tree_node->left);
	}

	//Prints the current node
	printData(tree_node);

	if (tree_node->right != NULL) {
		//There is a right node, so go on with it
		inorderPrint(tree_node->right);
	} else
		return; //Both left and right are empty - BASE STATEMENT
}

void postorderPrint(struct TreeNode *tree_node) {
	if (tree_node->left != NULL) {
		//There is a left node, so go on with it
		postorderPrint(tree_node->left);
	}
	if (tree_node->right != NULL) {
		//There is a right node, so go on with it
		inorderPrint(tree_node->right);
	}
	printData(tree_node);
	return; //Since it goes through both left and right first, this return is a base statement
}

unsigned long getBookKey(struct TreeNode *tree_node){
	return *tree_node->key;
}

const char *getBookTitle(struct TreeNode *tree_node){
	return getTitle(tree_node->book);
}

const char *getBookAuthor(struct TreeNode *tree_node){
	return getAuthor(tree_node->book);
}
