#include "strings.h"

void	putnbr(int nb) // wtf lol
{
	if (nb == -2147483648)
	{
		_putchar('-');
		_putchar(2 + '0');
		putnbr(147483648);
	}
	else if (nb < 0)
	{
		_putchar('-');
		putnbr(-nb);
	}
	else if (nb >= 10)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		_putchar(nb + '0');
}
