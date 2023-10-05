#include <stdlib.h>

void	*memccpy(void *restrict dst, const void *restrict src, int c, unsigned long n){
	unsigned char stop = (unsigned char)c;
	unsigned long i;

	i = 0;
	while (((unsigned char *)src)[i] && ((unsigned char *)src)[i] != stop && i <= n){
		((unsigned char*)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	if (((unsigned char *)src)[i] == stop){
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		return (&dst[i]);
	}
	else
		return (NULL);
}
