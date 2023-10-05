#include "wowie_lists.h"

//	lst_find_prev  - Find the previous link.
//--------------------------------------------------
//	ARGS: t_list
//	t_list:
//		*head
//		*current : the pointer we want the previous of.
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL current, head == current
//--------------------------------------------------
//	DESCRIPTION:
//	iteratively traverse the list untill ->next has the address of current
//--------------------------------------------------
//	NOTES:
//	head == current returns head.
//	returns NULL on error.


t_list		*lst_find_prev(t_list *head, t_list *current){
	if (!head){
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_HEAD);
		return (NULL);
	}
	if (head == current){
		return(head);
	}

	t_list *traveller = head;
	while (traveller->next != current){
		traveller = traveller->next;
	}
	return (traveller);
}
