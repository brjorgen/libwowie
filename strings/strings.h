#ifndef _STRINGS_H_
# define _STRINGS_H_
# define GNL_BUFF_SIZE 500
# include <sys/types.h>
# include <stdbool.h>
# include <stdint.h>
# include "../mem/mem.h"

// figure this out for cross compat.
/* # ifndef DARWIN */
/* 	# define NULL (void *)0 */
/* # endif */

char	*strchr(const char *s, const int c);
char	*strclean(char *str);
char	*strdup(const char *s);
char	*strnext(char *str, bool resetp);
char	*strstr(const char *haystack, const char *needle);
int	atoi(const char *str);
int	intlen(int n);
int	str_search_bin(char **array, char *target, int array_size);
int	strcmp(const char *const a, const char *const b);
size_t	strcspn(const char *s, const char *reject);
size_t	strlen(char const *str);
void	_strncpy(char *dest, const char *src, size_t size);
void	_putchar(char c);
void	putnbr(int nb);
void	putstr(const char *const str);

#endif /* _STRINGS_H_ */
