#include "wowie_tree.h"

void	tree_insert(t_tree *t, t_tree *leaf, int (cmp)(void *, void *)){
	int res;

	res = cmp(t, leaf);
	if (res < 0 || res == 0){
		t->l = leaf;
	}
	else {
		t->r = leaf;
	}
}
