#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("THE ELEMENT=%d\n",ptr->data);
        ptr=ptr->next;
    }

}

// deleting element at first
struct node *deleteFirst(struct node *head)
{
    struct node *ptr=head;
    head=head -> next;
    free(ptr);
    return head;

};
// deleting element at required index
struct node * deleteAtindex(struct node * head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}
// deleting at last
struct node *deleteAtLast(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
       p=p->next;
       q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
};
// delete the required value
struct node *deleteafter(struct node *head,int value)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL && q->data != value)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }

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
    struct node *fourth;
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=11;
    head->next=second;
    second->data=12;
    second->next=third;
    third->data=13;
    third->next=fourth;
    fourth->data=14;
    fourth->next=NULL;
    linkedListTraversal(head);
    printf("AFTER THE PROCESS ...\n");
    //head=deleteFirst(head);
    //head=deleteAtindex(head,1);
    //head=deleteAtLast(head);
    head=deleteafter(head,13);
    linkedListTraversal(head);

    return 0;
}
