#include <stdint.h>

uint32_t	u8stou32(uint8_t u8s[static 4u])
{
	uint32_t ret;

	ret = u8s[0u] << 24u
	      | u8s[1u] << 16u
	      | u8s[2u] << 8u
	      | u8s[3u] << 0u;

	return(ret);
}
