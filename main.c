#include<stdio.h>
#include<stdlib.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    // Create doubly linked list pointers and Inirially set to NULL because lists are empty
    Dlist *head1 = NULL, *tail1 = NULL;  // Ffirst operand
    Dlist *head2 = NULL, *tail2 = NULL;  // Second operand
    Dlist *headR = NULL, *tailR = NULL;  // Result
 
     char operator, sign;

// Validate command line arguments
if(validate_arguments(argc, argv) == FAILURE)
{
    printf("ERROR: Invalid arguments\n");
    // printf("Usage: ./a.out <num1> <operator> <num2>\n");
    
    return FAILURE;
}
// Validation successful
printf("INFO: Validation successful\n");

// Check signs of operands
if(check_signs(argv, &operator, &sign) == FAILURE)
    {
        printf("ERROR\n");
        return FAILURE;
    }
   
    // Store operand digits into doubly linked lists
   store_into_DLL(&head1, &tail1, argv[1]);
   store_into_DLL(&head2, &tail2, argv[3]);

   // Perform required arithmetic operation

   switch(operator)
   {
    //Addition
    case '+' :
            // Add digits from right to left
            // Handle carry if generated
              addition(tail1, tail2, &headR, &tailR);
              break;

    // Subtraction
    case '-':
           //Compare operands first
           if(compare(head1, head2) >= 0)  // Compare operands first
           {
            subtraction(tail1, tail2, &headR, &tailR);  // operand1 - operand2
           }
           else
           {
            subtraction(tail2, tail1, &headR, &tailR);  //operand2 - operand1
           }
           break; 
    
    // Multiplication      
    case 'x':
             // Multiply digit by digit
             // Store partial products
             // Add partial results
            multiplication(tail1, tail2, &headR, &tailR);
            break; 
     // Division       
     case '/':
            // Perform repeated subtraction
            // Store quotient
            division(head1, tail1, head2, tail2, &headR, &tailR);
            break;          
   }

//  Display final formatted result   
display_result(argv, headR, sign);
   
// Program execution completed successfully 
    return SUCCESS;
    
}