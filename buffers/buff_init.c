#include "../strings/strings.h"
# define BUFFSIZE 255

uint8_t	*buff_init(void)
{
	static uint8_t	buff[BUFFSIZE];
	uint8_t		*buff_ptr;

	buff_ptr = &buff[0];
	return (buff_ptr);
}
