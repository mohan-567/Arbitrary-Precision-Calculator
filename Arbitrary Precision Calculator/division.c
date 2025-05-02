#include "apc.h"
#include <stdio.h>

// Division logic
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (*head2 == NULL || (*head2)->data == 0) // Check for division by zero
    {
        printf("Error: Division by zero!\n");
        return FAILURE;
    }

    Dlist *temp1 = *head1;  // Dividend
    Dlist *temp2 = *head2;  // Divisor
    int dividend_digit = 0, divisor_digit = 0, quotient_digit = 0;
    int remainder = 0;

    // First, let's get the divisor's value
    divisor_digit = 0;
    while (temp2) {
        divisor_digit = divisor_digit * 10 + temp2->data;
        temp2 = temp2->next;
    }

    // Now, iterate over the dividend
    while (temp1)
    {
        // Update the current dividend digit
        dividend_digit = remainder * 10 + temp1->data;

        // Calculate the quotient for the current division step
        quotient_digit = dividend_digit / divisor_digit;
        insert_at_last(headR, tailR, quotient_digit);

        // Calculate the remainder for the next iteration
        remainder = dividend_digit % divisor_digit;

        // Move to the next digit in the dividend
        temp1 = temp1->next;
    }

    // Removing leading zeros from the result
    remove_leading_zeros(headR, tailR);

    // If no result was generated, insert a 0
    if (*headR == NULL)
    {
        insert_at_last(headR, tailR, 0);
    }

    return SUCCESS;
}
