#include "wowie_lists.h"

//	lst_search_brute_no_ref - search for a link without a reference link.
//--------------------------------------------------
//	ARGS:
//	t_list:
//		*head
//	fn ptr:
//		bool (f_search)(t_list *): predicate function for matching wanted link
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL search function.
//--------------------------------------------------
//	DESCRIPTION:
//	This function finds the wanted link by brute-forcing a predicate function
//	on the list. obviously, it should return true if it matches and false if not.
//--------------------------------------------------
//	NOTES:


t_list		*lst_search_brute_no_ref(t_list *head, bool *(f_search (t_list *))){
	bool err = false;
	if (!head){
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_HEAD);
		err = true;
	}
	if (!f_search){
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_FN);
		err = true;
	}
	if (err){
		return(NULL);
	}

	t_list *traveller;

	traveller = head;
	while (traveller && !f_search(traveller)){
		traveller = traveller->next;
	}
	return (traveller);
}
