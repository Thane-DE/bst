#ifndef BOOKTREE_H_
#define BOOKTREE_H_

struct TreeNode {
	struct Book *book;
	unsigned long key;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *new_tree_node(unsigned long ISBN, char *author, char *title);

struct TreeNode *bst_search(struct Node *tree_node, unsigned long key);

void bst_insert(struct TreeNode *tree_node, struct TreeNode *new_node);

void bst_clear(struct TreeNode *tree_node);

void printData(struct TreeNode *tree_node);

void preorderPrint(struct TreeNode *tree_node);

void inorderPrint(struct TreeNode *tree_node);

void postorderPrint(struct TreeNode *tree_node);

unsigned long getBookKey(struct TreeNode *tree_node);

const char *getBookTitle(struct Tree *tree_node);

const char *getBookAuthor(struct Tree *tree_node);

#endif /* BOOKTREE_H_ */
