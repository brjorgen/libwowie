#include "wowie_lists.h"
#include "../../mem/mem.h"

//	lst_new_link  - Allocate a new link and get a ptr to it.
//--------------------------------------------------
//	ARGS: void *, size_t 
//	void *:
//		whatever bullshit you wanna put in there.
//--------------------------------------------------
//	ERROR CHECKS:
//	NULL DATA, 0 size
//--------------------------------------------------
//	DESCRIPTION:
//	Allocate the link ptr, it's data by size, assigns
//	its size by size and sets next to NULL.
//	Returns NULL on error.
//--------------------------------------------------
//	TESTED: yes
//--------------------------------------------------
//	NOTES: 

t_list		*lst_new_link(void *data, size_t size){
	bool err = false;
	int errcode = E_NOERROR;
	t_list *new = NULL;

	if (!data){
		errcode = E_ALLOC_ATTEMPTED_NULL;
		err = true;
	}
	if (!size){
		errcode = E_ALLOC_ATTEMPTED_0_SIZE;
		err = true;
	}
	if (err != E_NOERROR){
		goto error;
	}

	new = malloc(sizeof(*new));
	if (!new){
		errcode = E_ALLOC_FAILED;
		goto error;
	}

	new->data = malloc(size);
	if (!new->data){
		errcode = E_ALLOC_FAILED;
		goto error;
	}

	wowie_memcpy(new->data, data, size);
	new->size = size;
	new->next = NULL;
	return (new);

error:
	LSTERR(errcode);
	if (new->data) free(new->data);
	if (new) free(new);
	return (NULL);
}
