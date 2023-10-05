void	*wowie_memset(void *b, int c, unsigned long len){
	while (--len){
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}
