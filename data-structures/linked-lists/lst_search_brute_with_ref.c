#include "wowie_lists.h"

//	lst_search_brute_with_ref - search for a link with a reference link.
//--------------------------------------------------
//	ARGS:
//	t_list:
//		*head
//		*find : the ref link to find
//	fn ptr:
//		bool (f_search)(t_list *): predicate function for matching two links
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL find, NULL search function.
//--------------------------------------------------
//	DESCRIPTION:
//	Finds the wanted link by brute-forcing a predicate function
//	that compares two links; one in the list, another with data we want to match in there.
//	Obviously, it should return true if it matches and false if not.
//--------------------------------------------------
//	NOTES:

t_list		*lst_search_brute_with_ref(t_list *head, t_list *find, bool *(f_search (t_list *, t_list *))){
	bool err = false;

	if (!head || !find){
		err = true;
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_HEAD & E_LST_SEARCH_ATTEMPTED_NULL_TAIL);
	}
	if (!f_search){
		err = true;
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_FN);
	}
	if (err){
		return (false);
	}

	t_list *traveller;

	traveller = head;
	while (traveller && !f_search(traveller, find)){
		traveller = traveller->next;
	}
	return (traveller);
}
