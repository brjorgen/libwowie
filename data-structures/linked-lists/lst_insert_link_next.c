#include "wowie_lists.h"

t_list		*lst_insert_link_next(t_list *current, t_list *new_link){
	t_list *traveller;

	traveller = current->next;
	current->next = new_link;
	new_link->next = traveller;
	return (new_link);
}
