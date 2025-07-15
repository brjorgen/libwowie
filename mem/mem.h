#ifndef _MEM_H_
# define _MEM_H_
# include <stdlib.h>

void	*wowie_memset(void *b, int c, unsigned long len);
void	wowie_bzero(void *s, unsigned long n);
void	*wowie_memchr(const void *s, int c, unsigned long n);
void	*wowie_memdup(const void *b, unsigned long n);
void	*wowie_memcpy(void *restrict dst, const void *restrict src, unsigned long n);
int	wowie_memcmp(void *a, void *b, size_t n);
void	wowie_memdump(uint8_t *data, size_t size);

# ifdef MEMORY_MONITORING
struct  {
	void *addr;
	size_t n;
	const char *file;
	const char *function;
	const int line;
}	allocation_data_t;

stack_t	wowie_get_stack(void);
#  define wowie_memalloc(size) wowie_memalloc_monitor(size, __FILE__, __FUNCTION__, __LINE__, wowie_mem_get_stack())
void	*wowie_memalloc_monitor(size_t n, const char *file, const char *function, const int line, stack_t wowie_allocation_stack);
# else
void	*wowie_memalloc(size_t n);
# endif 
void	free2darray(void **array, size_t size);

#endif /* _MEM_H_ */
