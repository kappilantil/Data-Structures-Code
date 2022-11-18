//Given head pointer of a linked list, sort the list using Selection Sort
//Input:  5->4->3->2->1
//Output: 1->2->3->4->5
//Algorithm:
//1) Traverse the list and find the minimum element.
//2) Swap the minimum element with the first element.
//3) Repeat the above steps for the remaining list.
//Time Complexity: O(n^2)
//Auxiliary Space: O(1)
//Below is the implementation of the above algorithm:
// C program for implementation of selection sort
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the singly linked list using selection sort
void selectionSort(struct Node *head)
{
    // Node current will point to head
    struct Node *current = head, *index = NULL, *min = NULL;

    if(head == NULL)
    {
        return;
    }
    else
    {
        while(current != NULL)
        {
            //Node min will point to node next to current
            min = current->next;

            //Node index will point to node next to min
            index = min->next;

            while(index != NULL)
            {
                /*
                 * If index node's data is less than min node's data
                 * then, assign value of index node to min
                 */
                if(index->data < min->data)
                {
                    min = index;
                }
                index = index->next;
            }

            /*
             * Swap the data between current node and min node
             */
            if(min != current)
            {
                swap(min, current);
            }
            current = current->next;
        }
    }
}

// Function to insert a node at the beginning of the Singly Linked List
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

// Function to print nodes in a given linked list
void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main()
{
    struct Node *a = NULL;

    // Let us create a unsorted linked lists to test the functions
    // Created lists shall be a: 2->3->20->5->10->15
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    printf("Linked List before sorting");

    printList(a);

    selectionSort(a);

    printf("Linked List after sorting");

    printList(a);

    return 0;
}



