#ifndef _HEAPS_H_
# define _HEAPS_H_
# include <stdint.h>
# include <stdlib.h>
# include <assert.h>
# include <stdbool.h>
# include "../../mem/mem.h"

typedef	struct	s_heap {
	void		**data;
	uint32_t	size_max;
	uint32_t	size_current;
	int32_t		(*cmp)(void *, void *);
}		t_heap;

/* Creation functions */
t_heap		*heap_create(int (*cmp_function)(void *, void *), size_t max);
t_heap		*heapify(int32_t (*cmp_function)(void *, void *), void **array, uint32_t n);

/* destruction functions */
void		heap_clear(t_heap *heap);
void		heap_destroy(t_heap *heap);

/* item insertion and deletion */
int32_t		heap_push(t_heap *h, void *key);
void		heap_key_del(t_heap heap);

/* access functions */
uint32_t	heap_get_index_p(uint32_t i);
uint32_t	heap_get_index_l(uint32_t i);
uint32_t	heap_get_index_r(uint32_t i);

/* misc */
void		*heap_peek(t_heap *heap);
void		*heap_pop(t_heap *heap);
bool		heap_empty_p(t_heap *heap);

# endif
