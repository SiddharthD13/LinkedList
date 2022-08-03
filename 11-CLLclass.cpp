#include <bits/stdc++.h>
using namespace std;

class cllnode
{
public:
    int data;
    cllnode *next;
    cllnode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

 class cll
 {
     cllnode *head,*tail;
     cll()
     {
         this->head=nullptr;
         this->tail=nullptr;
     }
     void insertatbeg(int data)
     {
         cllnode*newnode=new cllnode(data);
         if(head==nullptr)
         {
             head=newnode;
             tail=newnode;
         }
         else{
             newnode->next=head;
             head=newnode;
             tail->next=newnode;
         }
     }

     void insertatend(int data)
     {
         cllnode*newnode=new cllnode(data);
         cllnode*temp=head;
         if(temp=nullptr)
         {
             head=newnode;
             tail=newnode;
         }
         else
         {
             tail->next=newnode;
             tail=newnode;
             tail->next=head;
         }
     }
     void inseratmid(int data,int pos)
     {
         cllnode*newnode=new cllnode(data);
         cllnode*temp=head;
         if(temp=nullptr)
         {
             head=newnode;
             tail=newnode;
         }
           cllnode*temp=head;
   if(temp->next==nullptr) //if there is only one element 
   {
     tail->next=newnode;
     tail=newnode;
     tail->next=head;
     return;
   }
   int count=1;
   while(count<pos && temp->next!=head)
   {
       count++;
       temp=temp->next;
   }
   if(temp->next==head)
   {
     tail->next=newnode;
     tail=newnode;
     tail->next=head;
     return;
   }
   newnode->next=temp->next;
   temp->next=newnode;
     }
 };