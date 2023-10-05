#include "./wowie_tree.h"
#include <stdio.h>

void	tree_map_inorder(t_tree *t, void (f)(t_tree *)){
	if (t){
		f(t);
		tree_map_inorder(t->l, f);
		tree_map_inorder(t->r, f);
	}
}

void	tree_map_preorder(t_tree *t, void (f)(t_tree *)){
	if (t){
		tree_map_preorder(t->l, f);
		f(t);
		tree_map_preorder(t->r, f);
	}
}

void	tree_map_post(t_tree *t, void (f)(t_tree *)){
	if (t){
		tree_map_post(t->l, f);
		printf("entered l node -> %p\n", t);
		tree_map_post(t->r, f);
		printf("entered r node -> %p\n", t);
		f(t);
		printf("fn call t\n");
	}
}
