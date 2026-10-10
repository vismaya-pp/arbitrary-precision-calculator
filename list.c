#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist)); // Allocate memory for new node

    // If memory allocation fails, insertion is not possible
    if(new == NULL)
        return FAILURE;

    // Store given data    
    new->data = data;
    new->prev = NULL;
    new->next = *head;  // next points to current head

   
    if(*head == NULL) // If list is empty new node become both head and tail
    {
        *head = *tail = new;
       
    }
    else
    {
         (*head)->prev = new;  //Update current head's previous link
          *head = new;    // move head to new node
    }

    // Insertion successful
    return SUCCESS;
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist)); // Allocate memory for new node

    // Return failure if allocation fails
    if(new == NULL)
        return FAILURE;

    // Store data in new node    
    new->data = data;
    new->prev = NULL;
    new->next = NULL;  // Since insertion is at end , next = NULL

    if(*head == NULL) // If list is empty, new node become head and tail
    {
        *head = *tail = new;
        return SUCCESS;
    }

    // Link new node after current tail
    new->prev = *tail;
    (*tail)->next = new;

    *tail = new;  // Update tail pointer

    // Insertion successful
    return SUCCESS;
}

int store_into_DLL(Dlist **head, Dlist **tail, char *str)
{
    int i = 0;
    if(str[0] == '-')
        i = 1;

    // T raverse each character of operand    
    while(str[i])
    {
        // Allocate memory for new node
        Dlist *new = malloc(sizeof(Dlist));

        // Return failure if allocation fails
          if(new == NULL)
            return FAILURE;

        new->data = str[i] - '0';  // Convert character digit to integer

        new->next = NULL; // since inserting at end, next = NULL
        new->prev = *tail;  // prev points to current tail

        // If list is empty, new node becomes head and tail
        if(*head == NULL)
        {
            *head = *tail = new;
        }
        else
        {
            (*tail)->next = new;   //   Link new node after current tail
            *tail = new;    // update tail pointer
        } 

        i++;  // Move to next digit
    }

    // DLL creation successful
    return SUCCESS;
}