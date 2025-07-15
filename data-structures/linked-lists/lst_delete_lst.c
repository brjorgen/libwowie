#include "wowie_lists.h"

//	lst_delete_list - delete a whole fucking t_list.
//--------------------------------------------------
//	ARGS:
//	t_list:	head,
//	fn ptr:
//		bool (f)(t_list *) : function that deletes contents of data ptr
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL tail, NULL deletion function.
//--------------------------------------------------
//	DESCRIPTION:
//	Iterates over a t_list, frees the link's data pointer and the link itself. 
//--------------------------------------------------
//	NOTES:
//	do NOT free anything outside the CONTENTS of the _data_ pointer. 
//	In other words: DO NOT free the data pointer yourself, that's handled here.
//	should really be called clear.

void	lst_delete_lst(t_list **head, bool (f_data_delete)(t_list *)){
	if (!head){
		LSTERR(E_LST_DEL_ATTEMPTED_NULL);
		return;
	}

	t_list *next = NULL;
	t_list *traveller = *head;

	while (traveller){
		next = traveller->next;
		if (f_data_delete)
			f_data_delete(traveller->data);
		free(traveller->data);
		traveller->data = NULL;
		free(traveller);
		traveller = next;
	}
	*head = NULL;
}
