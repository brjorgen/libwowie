#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wowie_tree.h"

void print_node(t_tree *n) {
	if (!n) return;
	printf("Node %p -> '%s'\n", n, (char *)n->data);
}

void _node_clear(t_tree **n) {
	if (!n || !*n) return;
	printf("Clearing node %p\n", (void *)*n);
	free((*n)->data);
	(*n)->data = NULL;
	free(*n);
	*n = NULL;
	printf("... cleared\n");
}

int cmp_tree_nodes(void *a, void *b) {
	t_tree *n1 = (t_tree *)a;
	t_tree *n2 = (t_tree *)b;
	return strcmp((char *)n1->data, (char *)n2->data);
}

int main(void) {
	printf("=== wowie_tree test ===\n");

	t_tree *root = tree_new("m", 2);
	t_tree *n1 = tree_new("c", 2);
	t_tree *n2 = tree_new("x", 2);
	t_tree *n3 = tree_new("a", 2);
	t_tree *n4 = tree_new("f", 2);

	if (!root || !n1 || !n2 || !n3 || !n4) {
		fprintf(stderr, "Failed to allocate nodes.\n");
		return 1;
	}

	root->l = n1;
	root->r = n2;
	n1->l = n3;
	n1->r = n4;

	printf("\n--- Inorder traversal ---\n");
	tree_map_inorder(root, print_node);

	printf("\n--- Preorder traversal ---\n");
	tree_map_preorder(root, print_node);

	printf("\n--- Postorder traversal ---\n");
	tree_map_post(root, print_node);

	/* search tests */
	t_tree *found = tree_search(root, "f");
	if (found)
		printf("\nFound node: %p -> %s\n", found, (char *)found->data);
	else
		printf("\nNode 'f' not found.\n");

	/* clear the tree */
	printf("\n--- Clearing tree ---\n");
	tree_clear(&root, _node_clear);
	if (!root) printf("Tree successfully cleared.\n");

	return 0;
}
