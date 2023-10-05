#include "../strings/strings.h"

int	str_search_bin(char **array, char *target, int array_size){
	int mid;
	int left;
	int right;
	int diff;

	left = 0;
	right = array_size - 1;
	while (left <= right){
		mid = (int)((left + right) / 2);
		diff = strcmp(array[mid], target);
		if (diff == 0)
			return (mid);
		if (diff < 0)
			left = mid + 1;
		if (diff > 0)
			right = mid - 1;
	}
	return (-1);
}
