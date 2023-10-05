#include "wowie_lists.h"

void		*lst_fold(t_list *head, t_list *(f)(t_list *, t_list *)){
	bool err = false;
	if (!f){
		LSTERR(E_LST_FOLD_ATTEMPTED_NULL_FN);
		err = true;
	}
	if(!head){
		LSTERR(E_LST_FOLD_ATTEMPTED_NULL_HEAD);
		err = true;
	}
	if(!head->next){
		LSTERR(E_LST_FOLD_TOO_SMALL);
		err = true;
	}
	if (err){
		return (NULL);
	}

	t_list	*traveller;
	t_list	*result;
	bool	first_pass = false;

	traveller = head;
	result = NULL;
	if (!first_pass && traveller->next){
		first_pass = true;
		result = f(traveller, traveller->next);
		traveller = traveller->next->next;
	}
	while (traveller){
		result = f(result, traveller);
		traveller = traveller->next;
	}
	return (result);
}
