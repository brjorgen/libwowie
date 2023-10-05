#include "./strings.h"

size_t		strlen(char const *str)
{
	const uint8_t *str_ptr;

	str_ptr = (const uint8_t *)str;
	while (*str_ptr)
		str_ptr++;
	return ((const char *)str_ptr - str);
}
