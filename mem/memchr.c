void	*wowie_memchr(const void *s, int c, unsigned long n){
	unsigned char *traveller;
	traveller = (unsigned char *)s;

	while(traveller && *traveller != (unsigned char)c && n){
		traveller++;
		n--;
	}
	return (traveller);
}
