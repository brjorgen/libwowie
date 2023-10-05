#include "wowie_lists.h"

t_list	*lst_cpy_lst(t_list *head){
	t_list *cpy_head;
	t_list *traveller;
	t_list *cpy_traveller;

	traveller = head;
	cpy_head = lst_cpy_link(traveller);
	cpy_traveller = cpy_head->next;
	traveller = traveller->next;
	while (traveller){
		cpy_traveller = lst_cpy_link(traveller);
		cpy_traveller = cpy_traveller->next;
		traveller = traveller->next;
	}
	return(cpy_head);
}
