#include <stdint.h>

void		u16tou8s(uint16_t u16, uint8_t u8s[static 2u]){
	u8s[0] =  u16 >> 8;
	u8s[1] =  (u16 << 8) >> 8;
}

/* #include <stdio.h> */
/* int main(int argc, char *argv[]) */
/* { */
/* 	(void)argc, (void)argv; */
/* 	uint8_t u8s[2u] = {0}; */
/* 	uint16_t u16 = 0x2a2b; */
/* 	u16tou8s(u16, u8s); */
/* 	printf("%d %d\n", u8s[0], u8s[1]); */
/* 	return 0; */
/* } */
