#include "./strings.h"
#include "../mem/mem.h"

char	*strstr(const char *haystack, const char *needle){
	const char *haystackptr;
	const char *needleptr;

	if (!haystack)
		return (NULL);
	if (*needle == '\0')
		return (NULL);
	while (*haystack){
		haystackptr = haystack;
		needleptr = needle;
		while (*haystack && *needleptr && *haystack == *needleptr){
			haystack++;
			needleptr++;
		}
		if (!*needleptr)
			return (char *)haystackptr;
		haystack = haystackptr + 1;
	}
	return (NULL);
}
