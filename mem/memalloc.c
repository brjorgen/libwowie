#include "mem.h"
#include <stdlib.h>

#ifdef MEMORY_MONITORING
#include "../data-structures/stacks/wowie_stacks.h"

stack_t	wowie_mem_get_stack(void)
{
	static bool    init = false;
	static stack_t mem_alloc_stack = NULL;

	if (init == false)
	{
		mem_alloc_stack = stack_new(16u);
		init = true;
	}
	return (mem_alloc_stack);
}

void	dump_mem_stack(stack_t s){
	allocation_data_t info;

	while (!stack_epmty(s))
	{
		info = stack_pop(s);
		putstr("file:");
		putstr(info.file);
		putstr("\nline:");
		putstr(info.line);
		putstr("\nfunction:");
		putstr(info.function);
		putstr("\nallocation size:");
		putstr(info.size);
	}
}

void	wowie_mem_dump_stack(void)
{
	stack_t s = wowie_mem_get_stack();
	dump_mem_stack(s);
}

void	*wowie_memalloc_monitor(size_t n, const char *file, const char *function, const int line, stack_t wowie_allocation_stack){
	void *p;
	bool success;

	p = malloc(sizeof(unsigned char) * n);

	if (NULL != p){
		wowie_bzero(p, sizeof(unsigned char) * n);
		success = true;
	}

	stack_push(wowwie_allocation_stack, (allocstion_data_t *){p, n, file, function, line}, sizeof(uint64_t));
	return (p);
}

#else

void	*wowie_memalloc(size_t n){
	void *p;

	p = malloc(sizeof(unsigned char) * n);
	if (!p){
		return (NULL);
	}
	wowie_bzero(p, sizeof(unsigned char) * n);
	return (p);
}

#endif
