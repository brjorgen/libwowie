#include <stdlib.h>

int	wowie_memcmp(void *a, void *b, size_t n){
	unsigned char *ca = (unsigned char *)a;
	unsigned char *cb = (unsigned char *)b;
	size_t i = 0;

	while (i < n && ca[i] == cb[i]){
		i++;
	}
	return (ca[i] - cb[i]);
}
