#include "strings.h"

int		atoi(const char *str)
{
	long	i;
	long	n;
	long	nb;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = (nb * 10) + ((str[i]) - '0');
			i++;
		}
		return (nb * n);
	}
	return (0);
}
