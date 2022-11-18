//selection sort a linked list

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

selection sortNode(struct node *head)
{
    struct node *i, *j, *min;
    int temp;
    for (i = head; i->next != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->data < min->data)
            {
                min = j;
            }
        }
        temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->data;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = fifth;

    fifth->data = 1;
    fifth->next = NULL;

    selection sortNode(head);
    printList(head);
    return 0;
}

