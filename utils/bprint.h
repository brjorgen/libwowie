#ifndef _BPRINT_H_
# define _BPRINT_H_

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int     bprint(const char * restrict format, ...);

#endif /* _BPRINT_H_ */
