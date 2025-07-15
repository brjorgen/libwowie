#include <stdint.h>
#include <stdlib.h>

void	free2darray(void **array, size_t size){
	uint32_t i;

	for (i = 0; i < size; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
}
