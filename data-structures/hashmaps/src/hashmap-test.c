#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include "../inc/wowie-hashmaps.h"

#define TEST_ASSERT(cond, msg)					\
	do {							\
		if (!(cond)) {					\
			fprintf(stderr,				\
				"[TEST FAIL] %s:%d: %s\n",	\
				__FILE__, __LINE__, msg);	\
			exit(EXIT_FAILURE);			\
		} else {					\
			printf("[PASS] %s\n", msg);		\
		}						\
	} while (0)

static item_t make_item(char *key, void *val)
{
	item_t it;
	it.key = key;
	it.val = val;
	return it;
}

static void test_hash_basic(void)
{
	uint32_t h1 = hash((uint8_t *)"hello", 255, 0);
	uint32_t h2 = hash((uint8_t *)"hello", 255, 0);
	uint32_t h3 = hash((uint8_t *)"world", 255, 0);

	TEST_ASSERT(h1 == h2, "hash is deterministic");
	TEST_ASSERT(h1 < 255, "hash respects compressor range");
	TEST_ASSERT(h3 < 255, "hash respects compressor range");
}

static void test_hashmap_init_destroy(void)
{
	hashmap_t *hm = hashmap_init(16);

	TEST_ASSERT(hm != NULL, "hashmap_init returns non-NULL");
	TEST_ASSERT(hm->items != NULL, "hashmap items allocated");
	TEST_ASSERT(hm->length == 16, "hashmap length set correctly");
	TEST_ASSERT(hm->__hash_fn != NULL, "hash function set");

	hashmap_destroy(&hm);
	TEST_ASSERT(hm == NULL, "hashmap_destroy NULLs pointer");
}

static void test_hashmap_insert_get(void)
{
	hashmap_t *hm = hashmap_init(32);

	item_t it1 = make_item("alpha", (void *)0xdeadbeef);
	item_t it2 = make_item("beta",  (void *)0xcafebabe);

	TEST_ASSERT(
		hashmap_item_insert(hm, &it1) == HASHMAP_RET_OK,
		"insert alpha"
		);

	TEST_ASSERT(
		hashmap_item_insert(hm, &it2) == HASHMAP_RET_OK,
		"insert beta"
		);

	item_t *g1 = hashmap_item_get(hm, "alpha");
	item_t *g2 = hashmap_item_get(hm, "beta");

	TEST_ASSERT(g1 != NULL, "get alpha returns item");
	TEST_ASSERT(g2 != NULL, "get beta returns item");

	TEST_ASSERT(strcmp(g1->key, "alpha") == 0, "alpha key matches");
	TEST_ASSERT(g1->val == (void *)0xdeadbeef, "alpha value matches");

	TEST_ASSERT(strcmp(g2->key, "beta") == 0, "beta key matches");
	TEST_ASSERT(g2->val == (void *)0xcafebabe, "beta value matches");

	hashmap_destroy(&hm);
}

static void test_hashmap_delete(void)
{
	hashmap_t *hm = hashmap_init(32);

	item_t it = make_item("delete_me", (void *)0x1234);

	TEST_ASSERT(
		hashmap_item_insert(hm, &it) == HASHMAP_RET_OK,
		"insert delete_me"
		);

	TEST_ASSERT(
		hashmap_item_get(hm, "delete_me") != NULL,
		"delete_me exists before delete"
		);

	TEST_ASSERT(
		hashmap_item_delete(hm, "delete_me") == HASHMAP_RET_OK,
		"delete delete_me"
		);

	TEST_ASSERT(
		hashmap_item_get(hm, "delete_me") == NULL,
		"delete_me not found after delete"
		);

	hashmap_destroy(&hm);
}

/* This test assumes NO collision resolution exists */
static void test_hashmap_collision_detection(void)
{
	hashmap_t *hm = hashmap_init(1);

	item_t it1 = make_item("key1", (void *)0x1);
	item_t it2 = make_item("key2", (void *)0x2);

	TEST_ASSERT(
		hashmap_item_insert(hm, &it1) == HASHMAP_RET_OK,
		"insert first item"
		);

	TEST_ASSERT(
		hashmap_item_insert(hm, &it2) == HASHMAP_RET_ERROR,
		"collision detected and rejected"
		);

	hashmap_destroy(&hm);
}

int main(void)
{
	printf("=== hashmap tests ===\n");

	test_hash_basic();
	test_hashmap_init_destroy();
	test_hashmap_insert_get();
	test_hashmap_delete();
	test_hashmap_collision_detection();

	printf("=== all tests passed ===\n");
	return 0;
}
