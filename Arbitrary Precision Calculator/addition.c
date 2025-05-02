#include "apc.h"
#include <stdlib.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0, sum = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while (temp1 || temp2 || carry)
    {
        sum = carry;

        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->prev;
        }

        carry = sum / 10;
        int digit = sum % 10;

        if (insert_at_first(headR, tailR, digit) == FAILURE)
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}
