#include "./strings.h"

void	_strncpy(char *dest, const char *src, size_t size){
	size_t i;

	i = 0;
	while (src[i] && i <= size)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= size)
	{
		dest[i] = 0;
		i++;
	}
}
