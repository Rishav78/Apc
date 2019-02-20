#include<stdio.h>
#include<stdlib.h>
 struct Node
{
    int data;
    struct Node* next;
};

struct Node * shiftSmallLarge(struct Node *org)
{
    struct Node *ptr = org;
    struct Node *prev, *prev2;
    struct Node *current = org;

    int max;
    if(org==NULL)
    {
        return org;
    }
    max=org->data;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr->data<max)
        {
            max=ptr->data;
            prev2=prev;
            current=ptr;
        }
    }
    if(current->data!=org->data)
    {
        prev2->next=current->next;
        current->next=org;
        org=current;
    }
    ptr = org;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr->data>max)
        {
            max=ptr->data;
            prev2=prev;
            current=ptr;
        }
    }
    if(current->next!=NULL)
    {
        prev2->next=current->next;
        current->next=NULL;
        ptr->next=current;
    }
    return org;
}


int main()
{
    int i;
    scanf("%d",&i);
    struct Node *ptr1 = NULL;
    while(i>0)
    {
        struct Node *ptr = ptr1;
        if(ptr==NULL)
        {
          ptr1 = (struct Node*)malloc(sizeof(struct Node));
          scanf("%d",&(ptr1->data));
          ptr1->next = NULL;
        }
        else
        {
          while(ptr->next!=NULL)
          {
            ptr = ptr->next;
          }
          struct Node *ptr2 = (struct Node*)malloc(sizeof(struct Node));
          scanf("%d",&(ptr2->data));
          (ptr2)->next = NULL;
          ptr->next=ptr2;
        }
        i--;
    }

    struct Node *ptr = shiftSmallLarge(ptr1);
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
