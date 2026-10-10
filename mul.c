#include "apc.h"

int multiplication(Dlist *tail1, Dlist *tail2,
                   Dlist **headR, Dlist **tailR)
{
    Dlist *ptr2 = tail2;  //  ptr1 traverses second operand

    // headR1, tailR1 store final accumulated result
    Dlist *headR1 = NULL, *tailR1 = NULL;

    // zero_count tracks number of zeros to append for place value shifting
    int zero_count = 0;

    while(ptr2)
  {
    Dlist *ptr1 = tail1;  // ptr1 traverses first operand

    // headR2, tailR2 store current partial product
    Dlist *headR2 = NULL, *tailR2 = NULL;

    int carry = 0;

    // Multiply current digit of operand2 with every digit of operand1
    while(ptr1)
    {
      
        int product = (ptr1->data * ptr2->data) + carry;   // Multiply digits and include carry

        int digit = product % 10; // Extract result digit
        carry = product / 10;    // Update carry
 
           // Insert digit at front since multiplication proceeds right to left
            dl_insert_first(&headR2, &tailR2, digit);

           // Move to next digit of operand1
            ptr1 = ptr1->prev;
        }
        
        // Insert remaining carry if present
        if(carry)
            dl_insert_first(&headR2, &tailR2, carry);

        //append zeros 
        for(int i = 0; i < zero_count; i++)
        {
            Dlist *new = malloc(sizeof(Dlist));

            new->data = 0;
            new->next = NULL;
            new->prev = tailR2;

            if(tailR2)
                tailR2->next = new;
            else
                headR2 = new;

            tailR2 = new;
        }

     // If first partial product, assign directly to final result   
    if(headR1 == NULL)
      {
        headR1 = headR2;
        tailR1 = tailR2;
      }     
    else
     {
        // Add current partial product to accumulated result  
       Dlist *newHead = NULL;
       Dlist *newTail = NULL;

       addition(tailR1, tailR2, &newHead, &newTail);

       headR1 = newHead;
       tailR1 = newTail;
     }
       
        // Reset partial result pointers
        headR2 = tailR2 = NULL;

        zero_count++;  // Increase place value shift
        ptr2 = ptr2->prev;  // Move to next digit operand2
  }

    // Store final multiplication result
    *headR = headR1;
    *tailR = tailR1;

    return SUCCESS;
}
