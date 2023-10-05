#include <stdint.h>

void		u32tou8s(uint32_t u32, uint8_t u8s[static 4u]){
	u8s[0] = (u32 & 0xff000000) >> 24;
	u8s[1] = (u32 & 0x00ff0000) >> 16;
	u8s[2] = (u32 & 0x0000ff00) >> 8;
	u8s[3] = u32 & 0x000000ff;
}
