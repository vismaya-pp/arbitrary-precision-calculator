#include "apc.h"

void print_list(Dlist *head)
{
    if(head == NULL)   // Check whether list is empty 
    {
        printf("List empty\n");
        return;
    }

    // Traverse list from head to tail and print each digit
    while(head)
    {
        printf("%d", head->data);
        head = head->next; // Move to next node
    }
}
void display_result(char *argv[], Dlist *headR, char sign)
{
    printf("====================================================\n");
    printf("         ARBITRARY PRECISION CALCULATOR\n");
    printf("====================================================\n");

    printf("Operation -> %s %s %s\n", argv[1], argv[2], argv[3]);

    printf("Result -> ");

    if(sign == '-')
        printf("-");

    print_list(headR);

    printf("\n");
}