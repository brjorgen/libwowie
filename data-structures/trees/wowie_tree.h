#ifndef _TREE_H_
# define _TREE_H_
# include <stdlib.h>
# include "../../mem/mem.h"

typedef struct	s_tree {
	struct	s_tree *l;
	struct	s_tree *r;
	void	*data;
	size_t	size;
}		t_tree;

enum	tree_errors {
	E_TREE_ATTEMPTED_NULL,
	__E_TREE_MAX_ERR,
};


// module err stuff
extern const char *__g_error_tree_messages[__E_TREE_MAX_ERR];
# define TREE_ERR_ARRAY __g_error_tree_messages
# define TREEERR(errcode) error(__FILE__, __FUNCTION__, __LINE__, errcode, TREE_ERR_ARRAY)

t_tree	*tree_new(void *data, size_t n);
void	tree_insert(t_tree *t, t_tree *leaf, int (cmp)(void *, void *));
void	tree_delete(t_tree *t, void *data);
void	tree_map(t_tree *t, void (f)(t_tree *));
void	tree_map_inorder(t_tree *t, void (f)(t_tree *));
void	tree_map_preorder(t_tree *t, void (f)(t_tree *));
void	tree_map_post(t_tree *t, void (f)(t_tree *));
t_tree	*tree_search(t_tree *t, void *d);
/* void	tree_clear(t_tree *t); */
void	tree_clear(t_tree **t, void (f)(t_tree **));
#endif /* _TREE_H_ */

// todo: change header file name
