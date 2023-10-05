#include <stdio.h>

void	error(const char *function, // __FUNCTION__
	      const char *file, // __FILE__
	      const int line, // __LINE__
	      int error_code, // Enumerated error codes defined in module header
	      const char *__error_message_array[]) // array of error strings
{
	printf("%s (@ %s:%d) -> : \n", function, file, line);

	FILE *f = fopen(file, "r");
	int count = 0;
	if (file != NULL)
	{
		char line_buffer[256]; /* or other suitable maximum line size */
		while (fgets(line_buffer, sizeof line_buffer, f)) /* read a line */
		{
			if (count == line - 1)
				printf("-> %s\n", line_buffer);
			else
				count++;
		}
		fclose(f);
	}

	printf("[ERROR THROWN]-> %s\n", __error_message_array[error_code]);
}
