#include "wowie_lists.h"

t_list		*lst_map(t_list *head, void *(f)(t_list *)){
	bool err = false;
	if (!head){
		LSTERR(E_LST_MAP_ATTEMPTED_NULL);
		err = true;
	}
	if (!f){
		LSTERR(E_LST_MAP_ATTEMPTED_NULL_FN);
		err = true;
	}
	if (err){
		return (NULL);
	}

	t_list *traveller;

	traveller = head;
	while (traveller){
		f(traveller);
		traveller = traveller->next;
	}
	return (head);
}
static void	__lst_mapr_inplace_internal(t_list *traveller, void *(f)(t_list *)){
	if (traveller != NULL){
		f(traveller);
		__lst_mapr_inplace_internal(traveller->next, f);
	}
}

t_list		*lst_mapr_inplace(t_list *head, void *(f)(t_list *)){
	t_list *traveller;

	traveller = head;
	__lst_mapr_inplace_internal(traveller, f);
	return (head);
}

t_list		*lst_mapr_cpy(t_list *head, void *(f)(t_list *)){
	t_list *cpy = lst_cpy_lst(head);

	__lst_mapr_inplace_internal(cpy, f);
	return (cpy);
}
