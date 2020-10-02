#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>

struct linkedL
{
    /* data */
    int value;
    struct linkedL* next;
};

typedef struct linkedL node_t;

void add_group_list(node_t *ptr_list);
int main(){

    node_t n1,n2,n3;

    node_t *head;

    n1.value =45;
    n2.value = 23;
    n3.value =2;

    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;
add_group_list(head);
return 0;
}

void add_group_list(node_t *ptr_list){
	int i = 0;
	while(ptr_list) {
		i++;
		if(i % 20 == 0) printf("\n");
		printf(" ..%d ", ptr_list->value);
		ptr_list = ptr_list->next ;
   	}
	printf("\n");

}