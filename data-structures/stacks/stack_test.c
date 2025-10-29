#include "wowie_stacks.h"
#include <stdio.h>


#define TEST_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s, file %s, line %d. %s\n", \
                    #condition, __FILE__, __LINE__, message); \
        } \
    } while (0)

int main(void)
{
	printf("Initiating stack tests...\n");
	t_stack s = stack_new(10);
	t_stack s2 = stack_new(100);
	t_stack s3 = stack_new(500);

	(void)s2;
	(void)s3;
	printf("Stack creation test: pass\n");

	stack_push(s, &(int){1}, 1);
	stack_push(s, "Hello, World!", 13);
	printf("push test: pass\n");

	char *str = (char *)stack_pop(s);
	TEST_ASSERT((strcmp(str, "Hello, World!") == 0), "str != Hello World!");
	printf("\tpopped data: %s\n", str);

	int i = *(int *)stack_pop(s);
	TEST_ASSERT((i == 1), "i != 1");
	printf("\tpopped data: %d\n", i);

	printf("pop test: pass\n\n");

	i = 0;

	printf("pusing in a loop...\n");
	while (i < 10){
		stack_push(s, &(int){i}, 1);
		printf("\t%d\n", i);
		i++;
	}

	printf("popping in a loop...\n");
	while (i > 0){
		int j = *(int*)stack_pop(s);
		printf("\t%d\n", j);
		i--;
	}

	i = 0;
	printf("pushing in a loop to trigger overflow...\n");
	while (i < 11){
		stack_push(s, &(int){i}, 1);
		int k = *(int *)stack_peek(s);
		printf("\t%d == %d ? %i\n", k, i, k == i);
		TEST_ASSERT(k == i, "k != i");
		i++;
	}

	i = 9;

	printf("popping in a loop...\n");
	while (!stack_empty(s)){
		int *j = (int*)stack_pop(s);
		if (j == NULL)
			break;
		printf("\t%d == %d ? %d\n", i, *j, i == *j);
		TEST_ASSERT((*j == i), "*j != i");
		i--;
	}

	return 0;
}
