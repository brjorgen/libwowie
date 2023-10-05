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
//	Iteratively delete every link in the list.
//--------------------------------------------------
//	NOTES:
//	do NOT free anything outside the CONTENTS of the _data_ pointer. 
//	In other words: DO NOT free the data pointer yourself, that's handled here.
//	should really be called clear.

t_list		*lst_delete_lst(t_list *head, bool (f_data_delete)(t_list *)){
	bool err = false;
	if (!head){
		LSTERR(E_LST_DEL_ATTEMPTED_NULL);
		err = true;
	}
	if (err){
		return (head);
	}

	t_list *next;

	next = NULL;
	while (head){
		next = head->next;
		if (f_data_delete)
			f_data_delete(head->data);
		free(head->data);
		head->data = NULL;
		free(head);
		head = next;
	}
	return (head);
}
