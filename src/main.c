#include "booktree.h"
#include "books.h"
#include <stdio.h>

int main(void) {
	char* root_author;
	char* root_title;
	root_author = "A B C";
	root_title = "ABC";
	struct TreeNode root = *new_tree_node(579610, root_author, root_title);
	struct TreeNode* rp = 0;
	*rp = root;

	printData(rp);
	unsigned long test1 = getBookKey(rp);
	const char test2 = *getBookTitle(rp);
	const char test3 = *getBookAuthor(rp);

	char* n1a;
	char* n1t;
	n1a = "B C D";
	n1t = "BCD";
	struct TreeNode n1 = *new_tree_node(406759, n1a, n1t);
	struct TreeNode* n1p = 0;
	*n1p = n1;
	bst_insert(rp, n1p);

	char* n2a;
	char* n2t;
	n2a = "C D E";
	n2t = "CDE";
	struct TreeNode n2 = *new_tree_node(137950, n2a, n2t);
	struct TreeNode* n2p = 0;
	*n2p = n2;
	bst_insert(rp, n2p);

	char* n3a;
	char* n3t;
	n3a = "D E F";
	n3t = "DEF";
	struct TreeNode n3 = *new_tree_node(496780, n3a, n3t);
	struct TreeNode* n3p = 0;
	*n3p = n3;
	bst_insert(rp, n3p);

	char* n4a;
	char* n4t;
	n4a = "E F G";
	n4t = "EFG";
	struct TreeNode n4 = *new_tree_node(496746, n4a, n4t);
	struct TreeNode* n4p = 0;
	*n4p = n4;
	bst_insert(rp, n4p);

	char* n5a;
	char* n5t;
	n5a = "F G H";
	n5t = "FGH";
	struct TreeNode n5 = *new_tree_node(738135, n5a, n5t);
	struct TreeNode* n5p = 0;
	*n5p = n5;
	bst_insert(rp, n5p);

	preorderPrint(rp);
	printf("FEDDICH\n;");
	inorderPrint(rp);
	printf("FEDDICH\n");
	postorderPrint(rp);
	printf("FEDDICH\n");

	bst_clear(rp);

	return 0;
}
