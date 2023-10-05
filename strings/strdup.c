#include "strings.h"

char	*strdup(const char *s)
{
	char	*str;
	int	size;

	size = strlen(s);
	if (!s)
		return (NULL);

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);

	_strncpy(str, s, size);
	return (str);
}
