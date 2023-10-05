#include "wowie_lists.h"

//	lst_attach_end  - Attach a link to the end of a list.
//--------------------------------------------------
//	ARGS: t_list 
//	t_list:
//		*head
//		*new_tail : the new tail pointer of this list.
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL new_head
//--------------------------------------------------
//	DESCRIPTION:
//	finds the end of the list, assign the tail->next pointer
//	to new_tail.
//--------------------------------------------------
//	TESTED: yes
//--------------------------------------------------
//	NOTES:
//	returns NULL on error.

t_list		*lst_attach_end(t_list *head, t_list *new_tail){
	if (!head || !new_tail){
		LSTERR(E_LST_ATTACH_ATTEMPTED_NULL);
		return (NULL);
	}

	t_list *current_tail = NULL;

	current_tail = lst_find_end(head);
	if (!current_tail)
		return (NULL);
	current_tail->next = new_tail;
	return(head);
}
