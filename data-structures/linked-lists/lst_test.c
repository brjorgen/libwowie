#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wowie_lists.h"

void *print_node(t_list *t){
	printf("[MAP_FN]: %s (len: %zu)\n", (char *)t->data, strlen((char *)t->data));
	return (NULL);
}

void create_leak(void){
	
}

int main(void)
{
	printf("wowie list tests initiated.\n");
	
	char testing_strings[10][20] = {
		"Hello\0",
		"Goodbye\0",
		"I <3 charlotte\0",
		"Orange, door hinge\0",
		[4 ... 9] = "\0",
	};

	t_list *t = lst_new_link(testing_strings[0], strlen(testing_strings[0]));

	assert(t);
	assert(t->data);
	printf("\t New link created @ %p\n", t);

	printf("Initial Link creation : pass\n");
	
	for (int i = 1; *testing_strings[i]; i++){
		t_list *new = lst_new_link(testing_strings[i], strlen(testing_strings[i]));
		assert(new);
		assert(new->data);
		lst_attach_end(t, new);
		printf("\tNew link created @ %p and attached to %p.\n", new, t);
	}

	int len = lst_len(t);

	printf("\tCreated list has length %d\n", len);

	int i = 0;

	printf("\texpecting to do %d comparisons\n", len);
	t_list *traveller = t;
	while (traveller){
		assert(strcmp(traveller->data, testing_strings[i]) == 0);
		printf("\t\t%s == %s\n", (char *)traveller->data, testing_strings[i]);
		i++;
		traveller = traveller->next;
	}

	printf("\tdid %d comparisons.\n", i);
	printf("List building: pass\n");

	lst_map(t, print_node);
	printf("List map: pass\n\n");

	t_list *cpy = lst_map_cpy(t, print_node);
	assert(cpy);
	assert(cpy->next);
	printf("List map copy: pass\n\n");


	lst_mapr(t, print_node);
	printf("List map (recursive): pass\n\n");


	t_list *cpy2 = lst_mapr_cpy(t, print_node);
	printf("List map copy (recursive): pass\n\n");

	t_list *new = lst_new_link("caca", 4);
	lst_insert_link_next(t->next, new);
	printf("created and inserted new link containing caca @ location 3...\n");

	t_list *new2 = lst_new_link("peepee", 6);
	lst_insert_link_prev(t, t->next, new2);
	printf("created and inserted new link containing peepee @ location 2...\n");

	t_list *new3 = lst_new_link("pizza", 5);
	t_list *newhead = lst_attach_start(t, new3);
	printf("created and inserted new link containing peepee @ head...\n");

	lst_map(newhead, print_node);

	printf("Deleting list...\n");
	lst_delete_lst(&t, NULL);
	assert(!t);
	lst_delete_lst(&cpy, NULL);
	assert(!cpy);
	lst_delete_lst(&cpy2, NULL);
	assert(!cpy2);
	printf("List deletion: pass\n\n");

	/* printf("%p\n", t); */
	/* printf("%p\n", t->data); */
	/* printf("%p\n", t->next); */
	
	/* assert(!t); */
	/* while (1) { */
	/* 	; */
	/* } */

	printf("Wowie Lists Test: Passed.\n");
	return 0;
}
