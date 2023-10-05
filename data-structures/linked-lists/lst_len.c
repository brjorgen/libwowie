#include "wowie_lists.h"

size_t		lst_len(t_list *head){
	size_t i;
	t_list *traveller; 

	i = 0;
	traveller = head;
	while (traveller){
		i++;
		traveller = traveller->next;
	}
	return (i);
}
