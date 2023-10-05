#include "../mem/mem.h"
#include <stdbool.h>

char	*strnext(char *str, bool resetp)
{
	static size_t	front;
	static size_t	back;
	static char	buff[500];
	size_t		pos;

	if (!str)
		return (NULL);
	if (resetp)
		front = 0;
	pos = 0;
	wowie_bzero(buff, sizeof(buff));
	back = front;
	while (str[front] && str[front] != ' ')
		front++;
	while (str[back] && back != front){
		buff[pos] = str[back];
		back++;
		pos++;
	}
	front++;
	return (buff);
}
