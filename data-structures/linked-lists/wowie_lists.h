#ifndef _WOWIE_LISTS_H_
# define _WOWIE_LISTS_H_

# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>

# include "../../error/error.h"

enum	lst_errors {
	E_NOERROR,
	E_LST_ATTACH_ATTEMPTED_NULL,
	E_LST_SEARCH_ATTEMPTED_NULL_HEAD,
	E_LST_SEARCH_ATTEMPTED_NULL_TAIL,
	E_LST_SEARCH_ATTEMPTED_NULL_FN,
	E_LST_FIND_NO_LIST,
	E_LST_MAP_ATTEMPTED_NULL,
	E_LST_MAP_ATTEMPTED_NULL_FN,
	E_LST_FOLD_ATTEMPTED_NULL_FN,
	E_LST_FOLD_ATTEMPTED_NULL_HEAD,
	E_LST_FOLD_TOO_SMALL,
	E_LST_DEL_ATTEMPTED_NULL,
	__E_LST_MAX_ERR,
	E_ALLOC_ATTEMPTED_0_SIZE,
	E_ALLOC_ATTEMPTED_NULL,
	E_ALLOC_FAILED,
};

typedef struct	s_list {
	void		*data;
	size_t		size;
	struct	s_list	*next;
}		t_list;

// module err stuff
extern const char *__g_error_lst_messages[__E_LST_MAX_ERR];
# define LST_ERR_ARRAY __g_error_lst_messages
# define LSTERR(errcode) error(__FILE__, __FUNCTION__, __LINE__, errcode, LST_ERR_ARRAY)

t_list		*lst_new_link(void *data, size_t size);
t_list		*lst_find_end(t_list *head);
t_list		*lst_attach_end(t_list *head, t_list *new_tail);
t_list		*lst_attach_start(t_list *head, t_list *new_head);
t_list		*lst_search_brute_with_ref(t_list *head, t_list *find, bool *(f (t_list *, t_list *)));
t_list		*lst_search_brute_no_ref(t_list *head, bool *(f (t_list *)));
t_list		*lst_delete_link(t_list *head, t_list *to_delete, bool (f_data_delete)(t_list *));
t_list		*lst_clear(t_list *head, void (f_data_delete)(t_list *));
void		*lst_fold(t_list *head, t_list *(f)(t_list *, t_list *));
t_list		*lst_map(t_list *head, void *(f)(t_list *));
t_list		*lst_insert_link_next(t_list *current, t_list *new_link);
t_list		*lst_insert_link_prev(t_list *head, t_list *current, t_list *new_link);
t_list		*lst_find_prev(t_list *head, t_list *current);
t_list		*lst_cpy_link(t_list *link);
t_list		*lst_cpy_lst(t_list *head);
t_list		*lst_mapr_inplace(t_list *head, void *(f)(t_list *));
t_list		*lst_mapr_cpy(t_list *head, void *(f)(t_list *));
size_t		lst_len(t_list *head);
t_list		*lst_delete_lst(t_list *head, bool (f_data_delete)(t_list *));

#endif /* _WOWIE_LISTS_H_ */
