\\Code for linked lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked list.h"
// Function to create a new node
struct node *newNode(char *data)
{
struct node *new = (struct node *)malloc(sizeof(struct node));
new->data = data;
new->next = NULL;
return new;
}
// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct node **head, char *data)
{
struct node *new = newNode(data);
new->next = *head;
*head = new;
}
// Function to insert a node at the end of the linked list
void insertAtEnd(struct node **head, char *data)
{
struct node *new = newNode(data);
if (*head == NULL)
{
*head = new;
return;
}
struct node *last = *head;
while (last->next != NULL)
last = last->next;
last->next = new;
}
// Function to insert a node after a given node
void insertAfter(struct node *prev, char *data)
{
if (prev == NULL)
{
printf("Previous node cannot be NULL");
return;
}
struct node *new = newNode(data);
new->next = prev->next;
prev->next = new;
}
// Function to delete a node with a given key
void deleteNode(struct node **head, char *key)
{
struct node *temp = *head, *prev;
if (temp != NULL && strcmp(temp->data, key) == 0)
{
*head = temp->next;
free(temp);
return;
}
while (temp != NULL && strcmp(temp->data, key) != 0)
{
prev = temp;
temp = temp->next;
}
if (temp == NULL)
return;
prev->next = temp->next;
free(temp);
}
// Function to delete a node at a given position
void deleteNodeAtPosition(struct node **head, int position)
{
if (*head == NULL)
return;
struct node *temp = *head;
if (position == 0)
{ *head = temp->next;
free(temp);
return;
}
for (int i = 0; temp != NULL && i < position - 1; i++)
temp = temp->next;
if (temp == NULL || temp->next == NULL)
return;
struct node *next = temp->next->next;
free(temp->next);
temp->next = next;
}
// Function to print the linked list
void printList(struct node *node)
{
while (node != NULL)
{
printf("%s ", node->data);
node = node->next;
}
}
// Function to reverse the linked list
void reverse(struct node **head)
{
struct node *prev = NULL;
struct node *current = *head;
struct node *next = NULL;
while (current != NULL)
{
next = current->next;
current->next = prev;
prev = current;
current = next;
}
*head = prev;
}
// Function to find the middle of the linked list
void findMiddle(struct node *head)
{
struct node *slow = head;
struct node *fast = head;   if (head != NULL)
{       while (fast != NULL && fast->next != NULL)
{           fast = fast->next->next;
slow = slow->next;
}
printf("The middle element is [%s]