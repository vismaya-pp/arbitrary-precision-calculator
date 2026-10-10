#include "apc.h"
#include <ctype.h>

int validate_number(char *str)
{
    int i = 0;

    if(str[0] == '\0')  // Check if string is empty
       return FAILURE;

    // Check for negative sign  
     if(str[0] == '-')
    {
        i = 1;
        
        // Reject if only '-' is present
        if(str[i] == '\0')
            return FAILURE;
    }  

    // Check every remaining character and all must be digits
    while(str[i])
    {
        // If not digit , number is invalid
        if(!isdigit(str[i]))
        return FAILURE;
       i++; 
    }  

    // Number is valid
    return SUCCESS;

}

int validate_arguments(int argc, char *argv[])
{
    if(argc != 4)  //Total argc = 4
        return FAILURE;

    // Validate operator 
    if(argv[2][1] != '\0')
        return FAILURE;

    // Check if operator is valid
    if(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' &&
       argv[2][0] != '/')
    {
        return FAILURE;
    }

    // Validate first number 
    if(validate_number(argv[1]) == FAILURE)
        return FAILURE;

    // Validate second number 
    if(validate_number(argv[3]) == FAILURE)
        return FAILURE;

    // All arguments are valid    
    return SUCCESS;
}

int check_signs(char *argv[], char *operator, char *sign)
{
    // Extract operands and operator from command line arguments
    char *operand1 = argv[1];
    char *oper = argv[2];
    char *operand2 = argv[3];

    char op1, op2;

    op1 = (operand1[0] == '-') ? '-' : '+';   // Determine sign of first operand
    op2 = (operand2[0] == '-') ? '-' : '+';   // Determine sign of second operand
    
    // Addition 
    if(oper[0] == '+')
    {
        if(op1 == '-' && op2 == '-')
        {
            *operator = '+';
            *sign = '-';
        }
        else if(op1 == '+' && op2 == '-')
        {
            *operator = '-';
            // Result sign depends on larger operand
            *sign = (check_operands_for_subtraction(argv) == SUCCESS) ? '+' : '-';
        }
        else if(op1 == '-' && op2 == '+')
        {
            *operator = '-';
            // Sign depends on larger operand
            if(check_operands_for_subtraction(argv) == SUCCESS)
                *sign = '-';
            else
            *sign = '+'; 
        }
        else
        {
            *operator = '+';
            *sign = '+';
        }

        return SUCCESS;
    }

    // Subtraction 
    if(oper[0] == '-')
    {
        if(op1 == '-' && op2 == '-')
        {
            *operator = '-';
            *sign = (check_operands_for_subtraction(argv) == SUCCESS) ? '+' : '-';
        }
        else if(op1 == '+' && op2 == '-')
        {
            *operator = '+';
            *sign = '+';
        }
        else if(op1 == '-' && op2 == '+')
        {
            *operator = '+';
            *sign = '-';
        }
        else
        {
            *operator = '-';
            *sign = (check_operands_for_subtraction(argv) == SUCCESS) ? '+' : '-';
        }

        return SUCCESS;
    }

    // Multiplication and Division 
    if(oper[0] == 'x' || oper[0] == '/')
    {
        // Operation remains same
        *operator = oper[0];

        *sign = ((op1 != op2) ? '-' : '+'); // Different signs -> negative, same signs -> positive

        // Division by zero check
        if(oper[0] == '/')
        {
            if(atoi(operand2) == 0)
            {
                printf("Division not possible\n");
                return FAILURE;
            }
        }
        return SUCCESS;
    }

    // Invalid operator
    return FAILURE;
}

int check_operands_for_subtraction(char *argv[])
{
    // Extract operands
    char *num1 = argv[1];
    char *num2 = argv[3];

    // Ignore negative sign if present
    if(num1[0] == '-')
        num1++;

    if(num2[0] == '-')
        num2++;

    // Find length of both numbers   
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Longer number is larger
    if(len1 > len2)
        return SUCCESS;

    if(len2 > len1)
        return FAILURE;

    // If length equal , compare digit by digit    
    if(strcmp(num1, num2) >= 0)
        return SUCCESS;

    // num2 is larger    
    return FAILURE;
}

int compare(Dlist *head1, Dlist *head2)
{
    // Remove leading zeros from first operand
    while(head1 && head1->data == 0 && head1->next)
        head1 = head1->next;

     // Remove leading zeros from second operand   
    while(head2 && head2->data == 0 && head2->next)
        head2 = head2->next;

    // Temporary pointers for traversal
    Dlist *temp1 = head1, *temp2 = head2;

    int count1 = 0, count2 = 0;

    // Count digits in first operand
    while(temp1)
    {
        count1++;
        temp1 = temp1->next;
    }

    // Count digits in second operand
    while(temp2)
    {
        count2++;
        temp2 = temp2->next;
    }

    // If first number has more digits, it is greater
    if(count1 > count2)
        return 1;

     // If second number has more digits, it is greater   
    if(count2 > count1)
        return -1;
     
    // If digit counts are equal, compare digit by digit from left to right    
    while(head1 && head2)
    {
        // First differing digit decides which number is greater
        if(head1->data > head2->data)
            return 1;

        if(head2->data > head1->data)
            return -1;

        // Move to next digit    
        head1 = head1->next;
        head2 = head2->next;
    }

    // All digits are equal
    return 0;
}   

    