#include <stdint.h>

uint16_t	u8stou16(uint8_t u8s[static 2u])
{
	uint16_t ret;

	ret = u8s[0u] << 8u | u8s[1u];

	return (ret);
}
