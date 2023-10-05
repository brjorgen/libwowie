#include "wowie_tree.h"

t_tree	*tree_new(void *data, size_t n){
	t_tree	*t;

	t = (t_tree *)malloc(sizeof(*t));
	if (!t){
		return (NULL);
	}
	t->data = wowie_memdup(data, n);
	if (!t->data){
		free(t);
		return (NULL);
	}
	t->l = NULL;
	t->r = NULL;
	return (t);
}
