#include "apc.h"

int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1;  // temp1 -> Traverses first operand from right to left
    Dlist *temp2 = tail2;  //temp2 -> Traverses second operand from right to left

    int borrow = 0, diff;

    while(temp1 || temp2) //Continue until all digits of both operands are processed
    {
        // digit1 -> Current digit from operand1
        // digit2 -> Current digit from operand2
        int digit1 = 0, digit2 = 0;   // Initialize to 0 to handle unequal lengths

        // Fetch digit from first operand and Move pointer backward
        if(temp1)
        {
            digit1 = temp1->data;
            temp1 = temp1->prev;
        }

        // Fetch digit from second operand and Move pointer backward
        if(temp2)
        {
            digit2 = temp2->data;
            temp2 = temp2->prev;
        }

        // Subtract previous borrow from digit1
        digit1 -= borrow;

        // If digit1 is smaller than digit2, borrow 10 from next higher place
        if(digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else   
        {
            borrow = 0;
        }

        // Compute difference digit
        diff = digit1 - digit2;

        // Insert result at beginning
        dl_insert_first(headR, tailR, diff);
    }

   // Subtraction completed successfully
    return SUCCESS;
}
