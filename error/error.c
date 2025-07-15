#include <stdio.h>

void	error(const char *function, // __FUNCTION__
	      const char *file, // __FILE__
	      const int line, // __LINE__
	      int error_code, // Enumerated error codes defined in module header
	      const char *__error_message_array[]) // array of error strings
{
	printf("[ERROR THROWN] [%s in %s:%d ]-> %s\n", function, file, line, __error_message_array[error_code]);
}
