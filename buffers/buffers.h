#ifndef BUFFERS_H
# define BUFFERS_H
# include <stdbool.h>
# include "../mem/mem.h"
# include "../strings/strings.h"

# ifndef BUFFSIZE
#  define BUFFSIZE 500
# endif

char	*buff_init(void);
size_t	buff_get_remainder(const uint8_t *buff_ptr);
void	buff_clear(uint8_t *buff);
bool	buff_write(uint8_t *buff_ptr, const uint8_t *data, const size_t size);
bool	buff_flush(uint8_t *buff_ptr);
void	buff_read_input(uint8_t *buff);

#endif
