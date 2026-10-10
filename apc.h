#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

       //List functions 

/* Insert node at beginning of DLL */
int dl_insert_first(Dlist **head, Dlist **tail, int data);

/* Insert node at end of DLL */
int dl_insert_last(Dlist **head, Dlist **tail, int data);

/* Store operand digits into DLL */
int store_into_DLL(Dlist **head, Dlist **tail, char *str);


/* Perform arbitrary precision addition */
int addition( Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

/* Perform arbitrary precision subtraction */
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

/* Perform arbitrary precision multiplication */
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

/* Perform arbitrary precision division */
int division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR);


/* Validate complete command line arguments */
int validate_arguments(int argc, char *argv[]);

/* Validate individual operand */
int validate_number(char *str);

/* Determine actual operation and result sign */
int check_signs(char *argv[], char *operator, char *sign);

/* Compare operand magnitudes for subtraction */
int check_operands_for_subtraction(char *argv[]);


/* Compare two DLL numbers */
int compare(Dlist *head1, Dlist *head2);

/* Print digits stored in DLL */
void print_list(Dlist *head);

/* Display final formatted result */
void display_result(char *argv[], Dlist *headR, char sign);

#endif