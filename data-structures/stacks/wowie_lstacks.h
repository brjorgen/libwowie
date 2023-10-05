#ifndef _WOWIE_LSTACKS_H_
#define _WOWIE_LSTACKS_H_
# include "../linked-lists/wowie_lists.h"
# include "../../mem/mem.h"
# include <assert.h>

struct  s_lstack {
	t_list	*head;
	t_list	*top;
	size_t	top_pos;
	size_t	size;
};

typedef struct s_lstack *t_lstack;

extern t_lstack lstack_new(void *data, size_t allocation_size);
extern void	lstack_push(t_lstack s_ptr, void *to_push, size_t size);
extern void	*lstack_pop(t_lstack s_ptr, bool (*f)(t_list *));
extern void	*lstack_peek(t_lstack s_ptr);
extern void	lstack_cleanup(t_lstack *s_ptr_addr, void (*f)(t_list *));
#endif /* _WOWIE_LSTACKS_H_ */
