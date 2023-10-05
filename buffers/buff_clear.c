#include "./buffers.h"

void	buff_clear(uint8_t *buff){
	for (size_t i = 0; i < BUFFSIZE; i++){
		buff[i] = 0;
	}
}
