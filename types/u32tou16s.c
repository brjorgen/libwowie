#include <stdint.h>
#include <stdio.h>

void		u32tou16s(uint32_t u32, uint16_t u16s[static 2u]){
	u16s[0] = u32 >> 16;
	u16s[1] = (u32 << 16) >> 16;
}
