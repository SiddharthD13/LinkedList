#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node*next;
}node;

node*head =NULL;
node*tail=NULL;

void insertatbeg(int data)
{
   node*newnode=(node*)malloc(sizeof(node));
   newnode->data=data;
   newnode->next=NULL;
   if(head==NULL)
   {
       head=newnode;
       tail=newnode;
       return;
   }
    newnode->next=head;
    head=newnode;
    tail->next=head;
}

void insertatend(int data)
{
 node*newnode=(node*)malloc(sizeof(node));
   newnode->data=data;
   newnode->next=NULL;
   if(head==NULL)
   {
       head=newnode;
       tail=newnode;
       return;
   }
   tail->next=newnode;
   tail=newnode;
   tail->next=head;
}

void insertatmiddle(int data,int pos)
{
    node*newnode=(node*)malloc(sizeof(node));
   newnode->data=data;
   newnode->next=NULL;
   if(head==NULL)
   {
       head=newnode;
       tail=newnode;
       return;
   }
   node*temp=head;
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
void display()
{
    node*temp;
    temp=head;
    do
    {
        cout<<"Address= :"<<temp<<endl;
        cout<<temp->data<<" ";
        cout<<temp->next<<endl;
        temp=temp->next;
    }while (temp!=head);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
      int n;
      cin>>n;
      int data;
        for (int i = 0; i < n; i++)
        {
            cin>>data;
            insertatbeg(data);
        }
        
        cout<<"Insert at Beginning: ";
        display();
        cout<<endl;
        head=NULL;
        tail=NULL;

        for(int i=0;i<n;i++){
              cin>>data;
              insertatend(data);
        }
        cout<<"Insert at End: ";
        display();
        cout<<endl;

        int pos;
        cin>>pos;
        cin>>data;
        insertatmiddle(data,pos);
        cout<<"insert after pos"<<pos<<": ";
        display();
        cout<<endl;
        head=NULL;
        tail=NULL;
    }
 return 0;
}