#include "wowie_lists.h"

//	lst_attach_start  - Attach a link to the beginning of a list.
//--------------------------------------------------
//	ARGS: t_list 
//	t_list:
//		*head
//		*new_head : the new head pointer of this list.
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL new_head
//--------------------------------------------------
//	DESCRIPTION:
//	Assigns the next pointer of the new_head to the head and return this pointer,
//	now pointing to the new beginning of your list.
//--------------------------------------------------
//	TESTED: yes
//--------------------------------------------------
//	NOTES:

t_list		*lst_attach_start(t_list *head, t_list *new_head){
	if (!head || !new_head){
		LSTERR(E_LST_ATTACH_ATTEMPTED_NULL);
		return (NULL);
	}
	new_head->next = head;
	return(new_head);
}
