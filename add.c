#include "apc.h"

int addition( Dlist *tail1, Dlist *tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1; //temp1 -> Traverses first operand from right to left
    Dlist *temp2 = tail2; // temp2 -> Traverses second operand from right to left

    int sum =0, carry = 0, digit =0;

    //Continue loop until:
   //First operand digits are exhausted or Second operand digits are exhausted or No carry remains
    while(temp1 || temp2 || carry)
    {
       // Start each iteration with carry from previous addition
        digit = carry;
        
       // Add digit from first operand and Move pointer backward
       if(temp1)
       {
           digit += temp1->data;
           temp1 = temp1->prev;
       } 

       // Add digit from second operand and Move pointer backward
       if(temp2)
       {
          digit += temp2->data;
          temp2 = temp2->prev;
       }

       // Extract result digit
       sum = digit % 10;
       carry = digit/ 10;

       // Insert result digit at beginning
        dl_insert_first(headR, tailR, sum);  
    }
  
    // Addition completed successfully
    return SUCCESS;
}