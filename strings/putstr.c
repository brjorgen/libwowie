#include "./strings.h"
#include <unistd.h>

void	putstr(const char *const str)
{
	if (!str)
		write(1, "(null)", 6);
	else
		write(1, str, strlen(str));
}
