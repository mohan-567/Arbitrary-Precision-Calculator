#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1

// Doubly Linked List Structure
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

/* Function Prototypes */
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int compare_lists(Dlist *head1, Dlist *head2);
int insert_at_first(Dlist **head, Dlist **tail, int data);
int insert_at_last(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
void free_list(Dlist **head);
void remove_leading_zeros(Dlist **head, Dlist **tail);

#endif
