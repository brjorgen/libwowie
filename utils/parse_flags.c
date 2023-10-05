#include <stdint.h>
#include  "../search/search.h"
#include  "../strings/strings.h"

/* compile with -D __BITFIELD_TYPE [stdint type] i.e gcc -Wall -Werror -Wextra -D __BITFIELD_TYPE main.c */

#ifndef __BITFIELD_TYPE
# define __BITFIELD_TYPE uint8_t
#endif

#define __ARGUMENTS_MAX sizeof(__BITFIELD_TYPE) * 8u

uint8_t		parse_flags(uint8_t  **sorted_accepted_flags,
			    uint32_t sorted_accepted_flags_size,
			    uint8_t  **sorted_arguments,
			    uint32_t sorted_arguments_size)
{
	int32_t		search_res;
	__BITFIELD_TYPE	found_flags;
	uint8_t		i;

	search_res	= 0i;
	found_flags	= 0u;
	i		= 0u;

	while (i < sorted_arguments_size && (__BITFIELD_TYPE)i < __ARGUMENTS_MAX){
		search_res = search_bin((void **)sorted_accepted_flags, sorted_arguments[i], sorted_accepted_flags_size, (int (*)(void *, void *))&strcmp);

		if (search_res != -1){
			found_flags ^= (1u << search_res);
		}
		i++;
	}
	return(found_flags);
}
