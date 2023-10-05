void	*wowie_memcpy(void *restrict dst, const void *restrict src, unsigned long n){
	unsigned long i;
	i = 0;

	while (((unsigned char *)src)[i] && i <= n){
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
