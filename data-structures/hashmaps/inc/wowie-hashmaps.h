#ifndef LIBWOWIE_HASHMAP_SRC_H_
#define LIBWOWIE_HASHMAP_SRC_H_

/* ------------------------------------------------------------------------------
** INCLUDES
* ---------------------------------------------------------------------------- */
#include <stdint.h>
#include "../../../mem/mem.h"

/* ------------------------------------------------------------------------------
** LOCAL CONSTANTS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** EXTERNAL CONSTANTS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** ENUMERATIONS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** TYPE DEFINITIONS
* ---------------------------------------------------------------------------- */

typedef struct
{
	char	     *key;
	void	     *val;
}	item_t;

typedef struct {
	item_t	  *items;
	uint32_t  length;
	uint32_t  (*__hash_fn)(uint8_t *data, uint32_t size, uint32_t seed);
}	hashmap_t;

typedef enum {
	HASHMAP_RET_OK,
	HASHMAP_RET_ERROR,
	HASHMAP_RET_ALLOCATION_ERROR,
	__HASHMAP_ERROR_MAX
}	e_hashmap_return_code;

/* ------------------------------------------------------------------------------
** MACRO FUNCTIONS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** PUBLIC FUNCTION PROTOTYPES
* ---------------------------------------------------------------------------- */

uint32_t		crc32(uint8_t *data, uint32_t size, uint32_t init);
hashmap_t		*hashmap_init(uint32_t size);
e_hashmap_return_code	hashmap_destroy(hashmap_t **hashmap);
e_hashmap_return_code	hashmap_item_insert(hashmap_t *hashmap, item_t *item);
e_hashmap_return_code	hashmap_item_delete(hashmap_t *hashmap, char *key);
item_t			*hashmap_item_get(hashmap_t *hashmap,
					  char      *key);
#endif /* BULLSHIT_SRC_H_ */
