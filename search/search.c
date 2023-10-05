int		search_bin(void **array, void *target, int array_size, int (*__cmp_function)(void *, void *)){
	int mid;
	int left;
	int right;
	int diff;

	left = 0;
	right = array_size - 1;
	while (left <= right){
		mid = (int)((left + right) / 2);
		diff = __cmp_function(array[mid], target);
		if (diff == 0)
			return (mid);
		if (diff < 0)
			left = mid + 1;
		if (diff > 0)
			right = mid - 1;
	}
	return (-1);
}

int		search_brute(void **d, void *target, int array_size, int (*__cmp_function)(void *, void *)){
	for (int i = 0; i < array_size; i++){
		if (__cmp_function(target, d[i]))
			return(i);
	}
	return (-1);
}
