#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

// Converts digits in strings to doubly linked lists
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    void string_to_list(Dlist **head, Dlist **tail, char *num)
    {
        for (int i = 0; num[i] != '\0'; i++)
        {
            int digit = num[i] - '0';
            insert_at_last(head, tail, digit);
        }
    }

    string_to_list(head1, tail1, argv[1]);
    string_to_list(head2, tail2, argv[3]);
}

// Prints the elements of the list
void print_list(Dlist *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Frees the memory allocated for the list
void free_list(Dlist **head)
{
    Dlist *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Inserts a new node at the end of the list
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node)
        return FAILURE;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = *tail;

    if (*tail)
        (*tail)->next = new_node;
    else
        *head = new_node;

    *tail = new_node;
    return SUCCESS;
}

// Inserts a new node at the beginning of the list
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node)
        return FAILURE;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head)
        (*head)->prev = new_node;
    else
        *tail = new_node;

    *head = new_node;
    return SUCCESS;
}

int main(int argc, char *argv[])
{
    // Validate input arguments
    if (argc < 4)
    {
        printf("Usage: <program> <num1> <operator> <num2>\n");
        return FAILURE;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    char operator = argv[2][0];

    digit_to_list(&head1, &tail1, &head2, &tail2, argv);

    switch (operator)
    {
    case '+':
        if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
        {
            printf("Addition Result: ");
            print_list(headR);
        }
        break;

    case '-':
        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
        {
            printf("Subtraction Result: ");
            print_list(headR);
        }
        break;

    case 'x':
        if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
        {
            printf("Multiplication Result: ");
            print_list(headR);
        }
        break;

    case '/':
        if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
        {
            printf("Division Result: ");
            print_list(headR);
        }
        break;

    default:
        printf("Invalid operator.\n");
        break;
    }

    free_list(&head1);
    free_list(&head2);
    free_list(&headR);

    return 0;
}
