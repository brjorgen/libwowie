#include "strings.h"

char		*itoa(int n)
{
	long		nb;
	char		*ret;
	int		size;
	int		i;
	int		modulo;

	nb = (long)n;
	size = intlen(nb);
	if (!(ret = wowie_memalloc(size)))
		return (0);
	size = 0;
	if (n < 0)
	{
		ret[size++] = '-';
		nb = nb * -1;
	}
	i = intlen(nb);
	while (i > 0)
	{
		modulo = nb % i;
		ret[size++] = (nb / i) + 48;
		i = i / 10;
		nb = modulo;
	}
	return (ret);
}
