#ifndef _WOWIE_STACKS_H_
#define _WOWIE_STACKS_H_

# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>
# include <strings.h>
# include <string.h>
# include <assert.h>

# include "../../error/error.h"

# define STACK_DEFAULT_SIZE 255

/* # define DEBUG */

# ifdef DEBUG
struct	s_stack {
	void		**data;
	int		top;
	size_t		max_entries;
	size_t		*entry_sizes;
	size_t		__debug_mem_usage;
};
# endif

enum	stack_err {
	E_STACK_FULL,
	E_STACK_EMPTY,
	E_STACK_OK,
	E_STACK_ALLOC_FAILED,
	E_STACK_ABNORMAL,
	__E_STK_MAX_ERR,
};

extern const char *__g_error_stk_messages[__E_STK_MAX_ERR];
# define STK_ERR_ARRAY __g_error_stk_messages
# define STKERR(errcode) error(__FILE__, __FUNCTION__, __LINE__, errcode, STK_ERR_ARRAY)

typedef struct s_stack	*t_stack;

extern t_stack	stack_new(size_t allocation_size);
extern void	stack_push(t_stack s_ptr, void *to_push, size_t size);
extern void	*stack_pop(t_stack s_ptr);
extern void	*stack_peek(t_stack s_ptr);
extern void	stack_cleanup(t_stack s_ptr, void (f)(void *));

#endif /* _WOWIE_STACKS_H_ */
