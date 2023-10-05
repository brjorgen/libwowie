#include "./wowie_tree.h"
#include "../../mem/mem.h"
#include <assert.h>

t_tree	*tree_search(t_tree *t, void *d){
	assert(t); assert(d);

	int diff = wowie_memcmp(t->data, d, t->size);

	if (!diff)
		return (t);
	if (diff > 0)
		return (tree_search(t->l, d));
	else
		return (tree_search(t->r, d));
}
