#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node*next;
    struct node*prev;
}node;

node*head =NULL;
void insertAtBeg(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    if(head==NULL)
    {
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        return;
    }
    else
    {
        newnode->data = data;
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
}

void deleteatbeg()
{
   node*temp=head;
   if(temp==NULL)
   {
       cout<<"linked list is empty"<<endl;
       return;
   }
   if(temp->next=NULL)
   {
    head=NULL;
    free(temp);
    return;
   }
   head=head->next;
   head->prev=NULL;
   temp->next=NULL;
   free(temp);
}

void deleteatend()
{
    node*temp=head;
    if(temp==NULL)
    {
        cout<<"LINKED LIST IS EMPTY"<<endl;
        return;
    }
    if(temp->next==NULL) //when there is only one element
    {
      head=NULL;
      free(temp);
      return;
    }

    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node*temp1=temp->next; //temp1 is pointing to the last node 
    temp1->prev=NULL;
    temp->next=NULL; //temp is pointing to last node 
    free(temp1);
}

void deleteatemiddle(int pos)
{
  node*temp=head;
  node*temp=head;
    if(temp==NULL)
    {
        cout<<"LINKED LIST IS EMPTY"<<endl;
        return;
    }
    if(temp->next==NULL) //when there is only one element
    {
      head=NULL;
      free(temp);
      return;
    }
    int count=1;
    while(count<pos-1)
    {
        count++;
        temp=temp->next;
    }
    node*temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;
    temp1->next=NULL;
    temp1->prev=NULL;
    free(temp1);
}

void display()
{
   node* temp;
   temp=head;
   while(temp!=NULL) 
   {
       cout<<temp->data<<" ";
       temp=temp->next;
   }
}