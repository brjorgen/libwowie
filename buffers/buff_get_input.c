#include "./buffers.h"
#include <unistd.h>

void	buff_get_input(uint8_t *buff)
{
	uint8_t *pos;

	buff_clear(buff);
	read(0, buff, BUFFSIZE);
	if ((pos = (uint8_t *)strchr((char *)buff, '\n')) != NULL)
		*pos = '\0';
}
