#include <stdint.h>
#include <stdlib.h>

void	free2darray(void **array, size_t size){
	uint32_t i;

	for (i = 0; i < size; i++)
	{
		free((uint8_t *)array[i]);
		array[i] = NULL;
	}
	free(array);
}
