#include "./strings.h"

char	*strchr(const char *s, const int c){
	const uint8_t *ret_ptr;
	const uint8_t cc = (uint8_t)c;

	ret_ptr = (const uint8_t *)s;
	while (*ret_ptr){
		if (*ret_ptr == cc)
			return ((char *)ret_ptr);
		ret_ptr++;
	}
	return (NULL);
}
