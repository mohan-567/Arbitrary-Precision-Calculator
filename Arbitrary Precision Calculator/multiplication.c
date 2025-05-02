#include "apc.h"
#include <stdlib.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (*head1 == NULL || *head2 == NULL)
        return FAILURE;

    int len1 = 0, len2 = 0;
    Dlist *temp1 = *head1, *temp2 = *head2;

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

    int result_len = len1 + len2;
    int *result = (int *)calloc(result_len, sizeof(int));

    if (!result)
        return FAILURE;

    temp1 = *tail1;
    int i = 0;
    while (temp1)
    {
        int carry = 0;
        int n1 = temp1->data;

        temp2 = *tail2;
        int j = 0;
        while (temp2)
        {
            int n2 = temp2->data;
            int sum = n1 * n2 + result[i + j] + carry;

            carry = sum / 10;
            result[i + j] = sum % 10;

            temp2 = temp2->prev;
            j++;
        }

        if (carry > 0)
        {
            result[i + j] += carry;
        }

        temp1 = temp1->prev;
        i++;
    }

    int has_started = 0;
    for (int k = result_len - 1; k >= 0; k--)
    {
        if (result[k] != 0)
            has_started = 1;

        if (has_started)
        {
            insert_at_last(headR, tailR, result[k]);
        }
    }

    if (!*headR)
        insert_at_last(headR, tailR, 0);

    free(result);

    return SUCCESS;
}
