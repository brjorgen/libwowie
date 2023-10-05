#include "wowie-heaps.h"
#include <stdio.h>
#include <string.h>

t_heap		*heap_create(int32_t (*cmp_function)(void *, void *), size_t max){
	t_heap	*heap;

	heap = (t_heap *)malloc(sizeof(t_heap));
	assert(heap);

	heap->data = (void **)malloc(sizeof(void *) * (max + 1));
	assert(heap->data);

	heap->size_max = max + 1;
	heap->cmp = cmp_function;
	heap->size_current = 0;
	return (heap);
}

void	        heap_destroy(t_heap *heap){
	free(heap->data);
	free(heap);
}

static void	heap_swap(t_heap *h, uint32_t i, uint32_t j){
	assert (h && i >= 0 && i <= h->size_current &&
		j >= 0 && j <= h->size_current);

	void *tmp = h->data[i];
	h->data[i] = h->data[j];
	h->data[j] = tmp;
}

// k is size_current
static void	heap_fixup(t_heap *h, uint32_t k){
	assert(k <= h->size_current);

	uint32_t i = k;
	uint32_t p = heap_get_index_p(k);

	while (p > 0 && h->cmp(h->data[p], h->data[i]) > 0) {
		heap_swap(h, h->size_current, p);
		i = p;
		p = heap_get_index_p(i);
	}
}

int32_t		heap_push(t_heap *h, void *key){
        assert(h);

        if (h->size_current + 1 >= h->size_max)
		return (-1);

	h->size_current++;
	h->data[h->size_current] = key;
	heap_fixup(h, h->size_current);
	return (0);
}

t_heap		*heapify(int (*cmp_function)(void *, void *), void **array, uint32_t n){
	assert(array && n > 0);

	t_heap *new;
	uint32_t i = 0;
	new = heap_create(cmp_function, n);

	while (i < n){
		heap_push(new, array[i]);
		i++;
	}
	return (new);
}

void		heap_clear(t_heap *heap){
	wowie_memset(heap->data, 0, heap->size_current);
	heap->size_current = 0;
}

static uint32_t	heap_fixdown(t_heap * h, int k){
	assert(h);
	uint32_t i = k;
	uint32_t l = 2 * k;
	uint32_t r = 1 + l;
	uint32_t min = k;

        while (l <= h->size_current && r <= h->size_current) {
		if (h->cmp(h->data[l], h->data[r]) < 0)
			min = r;
		else if (h->cmp(h->data[l], h->data[r]) > 0)
			min = l;

		heap_swap(h, k, min);
		i = min;
		l = i * 2;
		r = l + 1;
	}
	return (min);
}

void		*heap_pop(t_heap *heap) {
        if (heap_empty_p(heap)){
		return (NULL);
	}

	heap_swap(heap, 1, heap->size_current);
        heap->size_current--;
        heap_fixdown(heap, heap->size_current);
	return (heap->data[0]);
}

uint32_t		heap_get_index_p(uint32_t i){
	return ((i % 2 == 0) ? i / 2 : (i - 1) / 2);
}

uint32_t		heap_get_index_l(uint32_t i){
	return ((2 * i) + 1);
}

uint32_t		heap_get_index_r(uint32_t i){
	return ((2 * i) + 2);
}

bool		heap_empty_p(t_heap *heap){
	return (heap->size_current == 0 ? true : false);
}

void		*heap_peek(t_heap *heap){
	return (heap_empty_p(heap) ? heap->data[1] : NULL);
}
