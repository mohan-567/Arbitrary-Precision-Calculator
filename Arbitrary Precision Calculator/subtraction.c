#include "apc.h"
#include <stdlib.h>

// Function to compare two doubly linked lists
// Returns 0 if equal, 1 if num1 > num2, -1 if num1 < num2
int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *temp1 = head1, *temp2 = head2;

    // Calculate lengths of both lists
    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Compare lengths
    if (len1 > len2)
        return 1; // num1 > num2
    if (len1 < len2)
        return -1; // num1 < num2

    // If lengths are equal, compare digit by digit
    temp1 = head1;
    temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            return 1; // num1 > num2
        if (temp1->data < temp2->data)
            return -1; // num1 < num2
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0; // Lists are equal
}

// Function to remove leading zeros from the result
void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
        else
            *tail = NULL; // List becomes empty
        free(temp);
    }

    // If the list becomes empty, add a single 0
    if (!*head)
    {
        insert_at_first(head, tail, 0);
    }
}

// Subtraction function
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0, diff;

    // Compare the two numbers
    int comparison = compare_lists(*head1, *head2);
    int is_negative = 0;

    if (comparison == -1)
    {
        // If num1 < num2, swap the lists and mark result as negative
        Dlist *temp = *head1;
        *head1 = *head2;
        *head2 = temp;

        temp = *tail1;
        *tail1 = *tail2;
        *tail2 = temp;

        temp1 = *tail1;
        temp2 = *tail2;

        is_negative = 1; // Mark result as negative
    }

    // Perform subtraction
    while (temp1 || temp2 || borrow)
    {
        int num1 = (temp1) ? temp1->data : 0;
        int num2 = (temp2) ? temp2->data : 0;

        // Subtract with borrow
        num1 -= borrow;

        if (num1 < num2)
        {
            borrow = 1;
            num1 += 10;
        }
        else
        {
            borrow = 0;
        }

        diff = num1 - num2;

        // Insert the result at the beginning of the result list
        if (insert_at_first(headR, tailR, diff) != SUCCESS)
        {
            return FAILURE; // Handle memory allocation failure
        }

        // Move to the previous node in each list
        if (temp1)
            temp1 = temp1->prev;
        if (temp2)
            temp2 = temp2->prev;
    }

    // Remove leading zeros from the result
    remove_leading_zeros(headR, tailR);

    // Mark the result as negative if needed
    if (is_negative)
    {
        (*headR)->data *= -1; // Make the most significant digit negative
    }

    return SUCCESS;
}
