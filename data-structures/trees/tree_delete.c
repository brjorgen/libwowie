#include "./wowie_tree.h"
#include <stdio.h>

void	node_clear(t_tree **n){
	printf("clearing node %p\n", &n);
	free((*n)->data);
	(*n)->data = NULL;
	free(*n);
	*n = NULL;
	printf("... cleared\n");
}

void	tree_print(t_tree *d){
	printf("=== print\n ");
	printf("%p -> %s\n", d, (char *)d->data);
	return ;
}

/* void	tree_clear(t_tree *t){ */
/* 	tree_map_post(t, tree_print); */
/* 	tree_map_post(t, node_clear); */
/* } */

void	tree_clear(t_tree **t, void (f)(t_tree **)){
	if (*t){
		tree_clear(&(*t)->l, f);
		printf("entered l node -> %p\n", t);
		tree_clear(&(*t)->r, f);
		printf("entered r node -> %p\n", t);
		f(t);
		printf("fn call t\n");
	}
}
