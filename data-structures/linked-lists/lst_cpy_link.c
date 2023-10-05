#include "wowie_lists.h"

t_list	*lst_cpy_link(t_list *link){
	t_list *cpy;
	
	cpy = lst_new_link(link->data, link->size);
	return (cpy);
}
