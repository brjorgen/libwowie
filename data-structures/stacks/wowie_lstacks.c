#include "./wowie_lstacks.h"
#include "./stdio.h"

/* wip */

/* struct  s_lstack { */
/* 	t_list	*head; */
/* 	t_list	*top; */
/* 	size_t	top_pos; */
/* 	size_t	size; */
/* }; */

t_lstack lstack_new(void *data, size_t size){
	assert(data); assert(size);
	t_lstack s_addr;

	s_addr = malloc(sizeof(*s_addr));

	if (!s_addr){
		return (NULL);
	}

	s_addr->head = lst_new_link(data, size);
	s_addr->top = s_addr->head;
	s_addr->top_pos = 0;
	return (s_addr);
}

void	lstack_push(t_lstack s_ptr, void *to_push, size_t size){
	t_list *n = lst_new_link(to_push, size);
	lst_attach_end(s_ptr->head, n);
	s_ptr->top = n;
	s_ptr->size++;
}

// Not sure about this one lol
void	*lstack_pop(t_lstack s_ptr, bool (*f)(t_list *)){
	void *ret = wowie_memdup(s_ptr->top->data, s_ptr->top->size);
	s_ptr->top = lst_delete_link(s_ptr->head, s_ptr->top, f);
	s_ptr->size--;
	return (ret);
}

// fair enough
bool	lstack_empty(t_lstack s){
	return (s->size == 0);
}

void	*lstack_peek(t_lstack s_ptr){
	return(s_ptr->top->data);
}

void	lstack_cleanup(t_lstack *s_ptr_addr, void (*f)(t_list *)){
	lst_clear(s_ptr_addr[0]->head, f);
	(*s_ptr_addr)->size = 0;
	(*s_ptr_addr)->top = NULL;
	(*s_ptr_addr)->head = NULL;
	free(*s_ptr_addr);
	*s_ptr_addr = NULL;
}
