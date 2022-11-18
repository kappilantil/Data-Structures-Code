//write a program to selection sort linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;
struct node *temp1=NULL;
struct node *temp2=NULL;
struct node *temp3=NULL;
struct node *temp4=NULL;
struct node *temp5=NULL;
struct node *temp6=NULL;
struct node *temp7=NULL;
struct node *temp8=NULL;
struct node *temp9=NULL;
struct node *temp10=NULL;
struct node *temp11=NULL;
struct node *temp12=NULL;

void create()
{
int i;
for(i=0;i<10;i++)
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&temp->data);
temp->next=NULL;
if(head==NULL)
{
head=temp;
tail=temp;
}
else
{
tail->next=temp;

tail=temp;
}
}
}
void display()
{
temp1=head;
while(temp1!=NULL)
{
printf("%d",temp1->data);
temp1=temp1->next;
}
}
void selectionsort()
{
temp2=head;
while(temp2!=NULL)
{
temp3=temp2->next;
while(temp3!=NULL)
{
if(temp2->data>temp3->data)
{
temp4->data=temp2->data;
temp2->data=temp3->data;
temp3->data=temp4->data;
}
temp3=temp3->next;
}
temp2=temp2->next;
}
}
void main()
{
create();
display();
selectionsort();
display();
}

