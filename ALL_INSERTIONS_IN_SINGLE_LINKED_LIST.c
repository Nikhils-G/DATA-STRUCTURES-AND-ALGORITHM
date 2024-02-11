#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linked(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("THE ELEMENTS=%d\n",ptr->data);
        ptr=ptr->next;
    }
}
// insertion at begin
struct node *insertatbegin(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
};
// insert at end
struct node *insertAtEnd(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr -> next= NULL;
    return head;
};
// insertion at index
struct node *insertAtIndex(struct node *head,int data,int index)
{
   struct node *ptr=(struct node*)malloc(sizeof(struct node));
   int i=0;
   ptr->data=data;
   struct node *p=head;
   while(i != index-1)
   {
       p=p->next;
       i++;
   }

   ptr->next=p->next;
   p->next=ptr;
   return head;

};
// insertion after the required node

struct node *insertAfterNode(struct node *head,struct node *prevnode,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;

    return head;

};


int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    struct node *second;
    second=(struct node*)malloc(sizeof(struct node));
    struct node *third;
    third=(struct node*)malloc(sizeof(struct node));
    struct node *four;
    four=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=four;
    four->data=40;
    four->next=NULL;
    linked(head);
    //head=insertatbegin(head, 12);
    //linked(head);
    printf("AFTER PROCESS=\n");
    //head=insertAtEnd(head, 17);
    //head=insertAtIndex(head,200,3);
    head=insertAfterNode(head,second,9);
    linked(head);
    return 0;
}
