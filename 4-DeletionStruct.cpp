#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node*next;
}node;

node*head =NULL;

void insertAtBeg(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next=head;
    head=newnode;
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
        insertAtBeg(data);
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