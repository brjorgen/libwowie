#include <strings.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>

void	wowie_memdump(uint8_t *data, size_t size){
	size_t i = 0;
	int j = 0;
	char buffer[255];

        while (i < size){
		printf("%2x%c", data[i], (i + 1) & 15 ? ' ' : '\n');
		i++;
	}
	while (i % 16){
		printf("%s%c", "00", (i + 1) & 15 ? ' ' : '\n');
		i++;
	}
}
