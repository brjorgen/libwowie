#include "./strings.h"

int	strcmp(const char *s1, const char *s2)
{
	const uint8_t	*ca;
	const uint8_t	*cb;

	if (!s1 || !s2)
		return (0);
	ca = (const uint8_t *)s1;
	cb = (const uint8_t *)s2;
	while ((*ca && *cb) && (*ca == *cb))
	{
		ca++;
		cb++;
	}
	return ((int)*ca - *cb);
}
