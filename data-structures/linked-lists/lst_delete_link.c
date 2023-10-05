#include "wowie_lists.h"

//	lst_delete_link - delete a link in a t_list.
//--------------------------------------------------
//	ARGS:
//	t_list:	head, tail of t_list
//	fn ptr:
//		bool (f)(t_list *) : function that deletes contents of data ptr
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL head, NULL tail, NULL deletion function.
//--------------------------------------------------
//	DESCRIPTION:
//	This function finds the previous link and attaches it to the next link,
//	cleans the memory inside the link with f_data_delete, and finally cleans
//	up t_link * internals.
//--------------------------------------------------
//	TESTED: WIP
//--------------------------------------------------
//	NOTES:
//	do NOT free anything outside the CONTENTS of the _data_ pointer. 
//	In other words: DO NOT free the data pointer yourself, that's handled here.

t_list		*lst_delete_link(t_list *head, t_list *to_delete, bool (f_data_delete)(t_list *)){
	bool err = false;

	if (!head || !to_delete){
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_HEAD);
		err = true;
	}

	if (!f_data_delete){
		LSTERR(E_LST_SEARCH_ATTEMPTED_NULL_FN);
		err = true;
	}

	if (err){
		return (NULL);
	}

	t_list *prev;

	prev = lst_find_prev(head, to_delete);
	prev->next = to_delete->next;

	if (!f_data_delete(to_delete)){
		exit(EXIT_FAILURE);
	}

	free(to_delete->data);
	to_delete->data = NULL;
	free(to_delete);
	to_delete = NULL;
	return (prev);
}
