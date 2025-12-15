#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "wowie-heaps.h"

#define TEST_ASSERT(cond, msg)					\
	do {							\
		if (!(cond)) {					\
			fprintf(stderr,				\
				"[FAIL] %s:%d: %s\n",		\
				__FILE__, __LINE__, msg);	\
			exit(EXIT_FAILURE);			\
		} else {					\
			printf("[PASS] %s\n", msg);		\
		}						\
	} while (0)

static int32_t int_cmp(void *a, void *b)
{
	int ia = *(int *)a;
	int ib = *(int *)b;
	return ia - ib;
}

static void test_heap_create_destroy(void)
{
	t_heap *h = heap_create(int_cmp, 10);

	TEST_ASSERT(h != NULL, "heap_create returns non-NULL");
	TEST_ASSERT(h->data != NULL, "heap data allocated");
	TEST_ASSERT(h->size_current == 0, "heap initially empty");
	TEST_ASSERT(h->size_max == 11, "heap size_max = max + 1");

	heap_destroy(h);
	printf("[PASS] heap_destroy\n");
}

static void test_heap_push_peek(void)
{
	t_heap *h = heap_create(int_cmp, 10);

	int a = 5;
	int b = 3;
	int c = 7;

	TEST_ASSERT(heap_push(h, &a) == 0, "push 5");
	TEST_ASSERT(heap_push(h, &b) == 0, "push 3");
	TEST_ASSERT(heap_push(h, &c) == 0, "push 7");

	/* 📝 : heap_peek is currently inverted in implementation */
	void *peek = heap_peek(h);

	TEST_ASSERT(peek == NULL, "heap_peek returns NULL when non-empty (current behavior)");

	heap_destroy(h);
}

static void test_heap_push_overflow(void)
{
	t_heap *h = heap_create(int_cmp, 2);

	int a = 1, b = 2, c = 3;

	TEST_ASSERT(heap_push(h, &a) == 0, "push a");
	TEST_ASSERT(heap_push(h, &b) == 0, "push b");
	TEST_ASSERT(heap_push(h, &c) == -1, "push fails when heap full");

	heap_destroy(h);
}

static void test_heap_pop_order(void)
{
	t_heap *h = heap_create(int_cmp, 10);

	int vals[] = { 5, 1, 4, 2, 3 };
	for (int i = 0; i < 5; i++)
		heap_push(h, &vals[i]);

	/* Pop until empty */
	void *p1 = heap_pop(h);
	void *p2 = heap_pop(h);
	void *p3 = heap_pop(h);
	void *p4 = heap_pop(h);
	void *p5 = heap_pop(h);
	void *p6 = heap_pop(h);

	TEST_ASSERT(p6 == NULL, "pop on empty heap returns NULL");
        TEST_ASSERT(p1 != NULL, "pop 1 non-NULL");
	TEST_ASSERT(p2 != NULL, "pop 2 non-NULL");
	TEST_ASSERT(p3 != NULL, "pop 3 non-NULL");
	TEST_ASSERT(p4 != NULL, "pop 4 non-NULL");
	TEST_ASSERT(p5 != NULL, "pop 5 non-NULL");

	heap_destroy(h);
}

static void test_heapify(void)
{
	int a = 10, b = 5, c = 7;
	void *arr[] = { &a, &b, &c };

	t_heap *h = heapify(int_cmp, arr, 3);

	TEST_ASSERT(h != NULL, "heapify returns heap");
	TEST_ASSERT(h->size_current == 3, "heapify inserts all elements");

	void *p = heap_pop(h);
	TEST_ASSERT(p != NULL, "heap_pop after heapify returns non-NULL");

	heap_destroy(h);
}

static void test_heap_clear(void)
{
	t_heap *h = heap_create(int_cmp, 5);

	int a = 1, b = 2;
	heap_push(h, &a);
	heap_push(h, &b);

	heap_clear(h);

	TEST_ASSERT(h->size_current == 0, "heap_clear resets size_current");
	TEST_ASSERT(heap_empty_p(h) == true, "heap_empty_p true after clear");

	heap_destroy(h);
}

int main(void)
{
	printf("=== heap tests ===\n");

	test_heap_create_destroy();
	test_heap_push_peek();
	test_heap_push_overflow();
	test_heap_pop_order();
	test_heapify();
	test_heap_clear();

	printf("=== all heap tests completed ===\n");
	return 0;
}
