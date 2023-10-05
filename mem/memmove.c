#include "mem.h"

void *wowie_memmove(void *dst, const void *src, unsigned long len){
	unsigned char *d = (unsigned char *)dst;
	unsigned char *s = (unsigned char *)src;

	if (s < d){
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	wowie_memcpy(d, s, len);
	return (d);
}
