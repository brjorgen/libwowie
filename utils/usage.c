
# include "../strings/strings.h"

void	usage(char *executable_name, char *module_descriptor, char *usage_string){
	putstr(module_descriptor);
	putstr("Usage: ");
	putstr(executable_name);
	_putchar(' ');
	putstr(usage_string);
}
