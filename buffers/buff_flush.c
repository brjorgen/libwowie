#include "buffers.h"
#include "../mem/mem.h"

bool	buff_flush(uint8_t *buff_ptr)
{
	if (!buff_ptr)
		return (false);
	putstr((const char *)buff_ptr);
	buff_clear(buff_ptr);
	return (true);
}
