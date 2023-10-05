#include "wowie_lists.h"

//	lst_find_end  - Find end of your list and get a ptr to it.
//--------------------------------------------------
//	ARGS: t_list 
//	t_list:
//		*head
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head
//--------------------------------------------------
//	DESCRIPTION:
//	iteratively traverse the list untill ->next has the address of NULL
//--------------------------------------------------
//	TESTED: yes
//--------------------------------------------------
//	NOTES: Will inf loop if list is cyclical (obviously)

t_list		*lst_find_end(t_list *head){
	if (!head){
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_HEAD);
		return (NULL);
	}

	t_list *traveller;

	traveller = head;
	while (traveller->next){
		traveller = traveller->next;
	}
	return (traveller);
}
