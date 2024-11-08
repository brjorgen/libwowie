
#include "./strings.h"

size_t	strcspn(const char *s, const char *reject)
{
	__attribute__((unused)) const uint8_t	*s_ptr;
	__attribute__((unused)) const uint8_t	*reject_ptr;
	size_t			seg_size;

	s_ptr = (const uint8_t *)s;
	reject_ptr = (const uint8_t *)reject;
	seg_size = 0;
	while (!strchr(s, *reject))
	{
		s_ptr++;
		reject_ptr++;
		seg_size++;
	}
	return (seg_size);
}
