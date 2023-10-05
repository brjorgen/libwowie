
# Table of Contents

1.  [Documentation](#orgf371dd3)


<a id="orgf371dd3"></a>

# Documentation

    uint8_t		*buff_init(void);

This returns a pointer to a static buffer declared on the stack.

This function spawns a static buffer of arbitrary
size on invocation and no memory management mechanisms are needed
as it is released on program exit.

Invoking this function will return a pointer to the beginning
of the buffer.

    bool		buff_set(uint8_t v);

sets entirety of buffer to value of byte v

    bool		buff_flush(char *buff_ptr);

writes the buffer to stdout zeroes it.

    bool		buff_flush_to(char *buff_ptr, int size, char *dest_ptr);

writes n bytes of buff<sub>ptr</sub> into dest<sub>ptr</sub>.

    bool		buff_flush_fd(int fd, char *buff_ptr, int size);

    void		buff_get_input(void);

zeroes the buffer, reads input from stdin, untill a \n is met,
where it's replaced with a zero.

    size_t	buff_get_remainder(const char *buff_ptr);

returns the amount free space left in the buffer

    bool	buff_write(char *buff_ptr, const char *data, const size_t size);

writes <span class="underline">size</span> bytes of data to the buffer.

    uint8_t	*buff_search(uint8_t *target);

   searches for the sequence of bytes target in buffer,
returns:

-   a pointer to the beginning of target in buffer if found

otherwise&#x2026;

-   returns  NULL otherwise.

