#ifndef _SEARCH_H_
#define _SEARCH_H_

int	search_bin(void **array, void *target, int array_size, int (*__cmp_function)(void *, void *));
int	search_brute(void **d, void *target, int array_size, int (*__cmp_function)(void *, void *));

#endif /* _SEARCH_H */
