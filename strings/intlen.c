int	intlen(int n)
{
	int i = 0;

	while (n != 0){
		n /= 10;
		i++;
	}
	return (i);
}
