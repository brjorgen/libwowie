/* ------------------------------------------------------------------------------
** INCLUDES
* ---------------------------------------------------------------------------- */
#include "wowie-hashmaps.h"
#include "mem.h"
#include "strings.h"

/* ------------------------------------------------------------------------------
** LOCAL CONSTANTS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** EXTERNAL CONSTANTS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** MACRO FUNCTIONS
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** PRIVATE FUNCTION PROTOTYPES
* ---------------------------------------------------------------------------- */
/* N/A */

/* ------------------------------------------------------------------------------
** PUBLIC FUNCTION DEFINITIONS
* ---------------------------------------------------------------------------- */

uint32_t		hash(uint8_t *key, uint32_t compressor, uint32_t seed)
{
	uint32_t hash		= crc32(key, strlen((char *)key), seed);
	uint32_t compressed_hash = hash % compressor;
	return (compressed_hash);
}

hashmap_t		*hashmap_init(uint32_t base_size)
{
	hashmap_t	*hashmap;
	uint32_t	size;

	size = base_size;

	if (0u == size)
		size = 255u;

	hashmap		= (hashmap_t *)wowie_memalloc(sizeof(uint8_t) * sizeof(hashmap_t));
	wowie_bzero(hashmap, sizeof(uint8_t) * sizeof(hashmap_t));
	hashmap->items	= (item_t *)wowie_memalloc(sizeof(item_t) * size);
	hashmap->length	= size;
	hashmap->__hash_fn = hash;

	if (!hashmap || !hashmap->items)
	{
		free(hashmap->items);
		hashmap->items = NULL;
		free(hashmap);
		hashmap = NULL;
	}

	return (hashmap);
}

e_hashmap_return_code	hashmap_destroy(hashmap_t **hashmap_addr)
{
	free((*hashmap_addr)->items);
	(*hashmap_addr)->items = NULL;
	/* assert(!h->items); */
	free(*hashmap_addr);
	*hashmap_addr = NULL;
	/* assert(!h); */
	return (HASHMAP_RET_OK);
}

e_hashmap_return_code	hashmap_item_insert(hashmap_t *hashmap,
					    item_t    *item)
{
	uint32_t hash = hashmap->__hash_fn((uint8_t *)item->key, hashmap->length, 0);
	/* uint32_t compressed_hash = hashmap->__compressor_fn(hash); */

	if (hashmap->items[hash].val){
		/* found a colision */
		return (HASHMAP_RET_ERROR);
	}

	hashmap->items[hash].val = item->val;
	hashmap->items[hash].key = item->key;
	return (HASHMAP_RET_OK);
}

e_hashmap_return_code	hashmap_item_delete(hashmap_t *hashmap,
					    char      *key){
	item_t *i = hashmap_item_get(hashmap, key);
	if (!i){
		return (HASHMAP_RET_ERROR);
	}
	i->key = 0;
	i->val = 0;
	return (HASHMAP_RET_OK);
}

item_t			*hashmap_item_get(hashmap_t *hashmap,
					  char      *key)
{
	uint32_t hash;
	uint32_t compressed_hash;

	hash		= crc32((uint8_t *)key, strlen(key), 0);
	compressed_hash	= hash % hashmap->length;
	if (!hashmap->items[compressed_hash].key){
		return (NULL);
	}
	return (&hashmap->items[compressed_hash]);
}

/* ------------------------------------------------------------------------------
** PRIVATE FUNCTION DEFINITIONS
* ---------------------------------------------------------------------------- */
/* N/A */
