#include "apc.h"

int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Dlist **headR, Dlist **tailR)
{
    // Check division by zero
    // If divisor is NULL or contains only one node with 0, division is not possible
     if(head2 == NULL || (head2->data == 0 && head2->next == NULL))
        return FAILURE;


    Dlist *T1H = NULL, *T1T = NULL;  // Temporary dividend
    Dlist *hRem = NULL, *tRem = NULL;  // Stores remainder after subtraction

    Dlist *temp = head1;   // trmp traverses dividend digit by digit

    int count;
 
    // Process dividend from left to right
    while(temp)
    {
        //Append next digit from dividend into temporary dividend
        dl_insert_last(&T1H, &T1T, temp->data);

        //Check subtraction possible if temporary dividend >= divisor
        if(compare(T1H, head2) >= 0)
        {
            count = 0;

            // Repeatedly subtract divisor until temporary dividend becomes smaller
            while(compare(T1H, head2) >= 0)
            {
                hRem = tRem = NULL;   // Reset remainder pointers

                // Perform subtraction
                subtraction(T1T, tail2, &hRem, &tRem);

                // Update temporary dividend with remainder
                T1H = hRem;
                T1T = tRem;

               // Remove leading zeros
              while(T1H && T1H->data == 0 && T1H->next)
              {

                 T1H = T1H->next;
                 T1H->prev = NULL;
              }
                count++;  // Increment quotient digit count
            }
            // Insert quotient digit 
            dl_insert_last(headR, tailR, count);
        }
        else
        {
            // If quotient already started, insert zero
             if(*headR != NULL)
                dl_insert_last(headR, tailR, 0);
        }
    
        // Move to next digit of dividend
        temp = temp->next;
    }
 
    // If quotient is empty result is zero
    if(*headR == NULL)
        dl_insert_last(headR, tailR, 0);

        
    return SUCCESS;
}