#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*next;
};

struct node* createList(struct node*head)
{
    struct node *newnode,*temp;

    for(int i=0;i<=5;i++)
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      
      if(newnode == NULL)
      {
          return head;
      }
      newnode->data=i;
      newnode->next=NULL;

      if(head == NULL)
      {
          head=newnode;
          temp=head;
      }

      temp->next=newnode;
      temp=newnode;


    }
       
    return head;
}

void printList(struct node * head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node*head=NULL;
    head=createList(head);
    printList(head);
    return 0;
}