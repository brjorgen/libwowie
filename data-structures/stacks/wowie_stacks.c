#include "./wowie_stacks.h"
#include <stdbool.h>

t_stack	stack_new(size_t max_entries){
	t_stack ret;
	size_t allocation_size;

	ret = malloc(sizeof(*ret));
	if (!ret){
		STKERR(E_STACK_ALLOC_FAILED);
		return (NULL);
	}

	allocation_size = (max_entries == 0 ? STACK_DEFAULT_SIZE : max_entries);
	ret->data = malloc(allocation_size);
	if (!ret->data){
		STKERR(E_STACK_ALLOC_FAILED);
		free(ret);
		return (NULL);
	}
	bzero(ret->data, allocation_size);

	ret->entry_sizes = (size_t *)malloc(sizeof(size_t) * allocation_size);
	if (!ret->entry_sizes){
		STKERR(E_STACK_ALLOC_FAILED);
		free(ret->data);
		free(ret);
		return (NULL);
	}

	ret->max_entries = allocation_size;
	ret->top = -1;
	ret->__debug_mem_usage = 0;
	return (ret);
}

void	stack_push(t_stack s_ptr, void *to_push, size_t entry_size){
	assert(s_ptr); assert(to_push); assert(entry_size != 0);

	if (s_ptr->top == (long)s_ptr->max_entries - 1){
		STKERR(E_STACK_FULL);
		return;
	}

	size_t size;
	size = sizeof(uint8_t) * entry_size;
	s_ptr->top++;
	s_ptr->data[s_ptr->top] = malloc(size);
	if (!s_ptr->data[s_ptr->top]){
		STKERR(E_STACK_ALLOC_FAILED);
		stack_cleanup(&s_ptr, NULL);
		exit(EXIT_FAILURE);
	}
	memcpy(s_ptr->data[s_ptr->top], to_push, size);
	s_ptr->entry_sizes[s_ptr->top] = size;
	s_ptr->__debug_mem_usage += size;
}

void *stack_pop(t_stack s_ptr) {
	void *ret;

	if (!s_ptr || s_ptr->top == -1) {
		STKERR(E_STACK_EMPTY);
		return NULL;
	}

	if (!s_ptr->data[s_ptr->top]) {
		STKERR(E_STACK_ABNORMAL);
		return NULL;
	}

	size_t size = s_ptr->entry_sizes[s_ptr->top];
	ret = malloc(size);
	if (!ret) {
		STKERR(E_STACK_ALLOC_FAILED);
		stack_cleanup(&s_ptr, NULL);
		return NULL;
	}

	memcpy(ret, s_ptr->data[s_ptr->top], size);
	free(s_ptr->data[s_ptr->top]);
	s_ptr->data[s_ptr->top] = NULL;
	s_ptr->top--;

	return ret;
}

void	*stack_peek(t_stack s_ptr){
	return (s_ptr->data[s_ptr->top]);
}

bool	stack_empty(t_stack s_ptr){
	return ((s_ptr->top == -1));
}

bool	stack_full(t_stack s_ptr){
	return ((size_t)s_ptr->top == s_ptr->max_entries);
}

int	stack_top(t_stack s_ptr){
	return(s_ptr->top);
}

int	stack_check(t_stack s_ptr){
	bool empty = stack_empty(s_ptr);
	bool full = stack_full(s_ptr);
	if (!empty && !full){
		STKERR(E_STACK_OK);
		return (E_STACK_OK);
	}
	if (empty){
		STKERR(E_STACK_EMPTY);
	}
	if (full){
		STKERR(E_STACK_FULL);
	}
	return (E_STACK_ABNORMAL);
}

void	stack_cleanup(t_stack *s_ptr, void (*f)(void *)) {
	if (!s_ptr || !*s_ptr)
		return;

	t_stack s = *s_ptr;

	while (s->top >= 0) {
		void *elem = s->data[s->top];

		if (f && elem)
			f(elem);

		free(elem);
		s->data[s->top] = NULL;
		s->top--;
	}

	free(s->data);
	free(s->entry_sizes);
	free(s);

	*s_ptr = NULL;
}
