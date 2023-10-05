#include "wowie_lists.h"

t_list		*lst_insert_link_prev(t_list *head, t_list *current, t_list *new_link){
	t_list *prev;

	prev = lst_find_prev(head, current);
	prev->next = new_link;
	new_link->next = current;
	return (new_link);
}
