#include "strings.h"

char	*strclean(char *str){
	size_t	len;

	if (!str)
		return (NULL);
	len = strlen(str);
	while (*str == ' '){
		str++;
	}
	while (str[len] == ' '){
		str[len] = 0;
		len--;
	}
	return (str);
}
