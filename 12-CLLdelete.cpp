#include <bits/stdc++.h>
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
void deleteatbeg()
{
   node*temp=head;
   if(temp==NULL)
   {
       cout<<"linked list is empty"<<endl;
       return;
   }
   head=head->next;
   tail->next=head;
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
      tail=NULL;
      free(temp);
      return;
    }

    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    node*temp1=tail; //temp1 is pointing to the last node 
    temp->next=head; //temp is pointing to last node 
    temp1->next=NULL;
    tail=temp;
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
      tail=NULL;
      free(temp);
      return;
    }
    int count=1;
    while(count<pos-1 && temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    if(temp->next==head)
    {
        node*temp1=tail;
        temp->next=head;
        tail=temp;
        free(temp);
    }
    node*temp1=temp->next;
    temp->next=temp1->next;
    temp1->next=NULL;
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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    int n;
    cin>>n;
    int data;
    cin>>data;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertatbeg(data);
    }
    cout<<"Insert at beginning: ";
    display();
    cout<<endl;

    cout<<"After delete at end: ";
    deleteatend();
    display();
    cout<<endl;

    int pos;
    cin>>pos;
    cout<<"After delete at position"<<pos<<":";
    deleteatemiddle(pos);
    display();

    head=NULL; //FOR NEW TEST CASES 

    }
 return 0;
}