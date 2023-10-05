#include <stdint.h>

uint32_t	u16stou32(uint8_t u16s[static 2u])
{
	uint32_t ret;

	ret = (u16s[0] & 0xFF00) | (u16s[1] & 0x00FF);

	return (ret);
}
