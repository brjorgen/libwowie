#include <stdlib.h>

void	*wowie_memdup(const void *b, unsigned long n){
	unsigned char *s;
	unsigned char *ret;
	unsigned long i;

	s = (unsigned char *)b;
	i = 0;
	ret = malloc(n);
	if (!ret)
		return (NULL);
	while (i <= n){
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
