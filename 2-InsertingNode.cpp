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

void insertAtEnd(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    node*temp=head;

    if(temp==NULL)
    {
        head=newnode;
        return;
    }
    while(temp->next!=NULL){
        temp->next=newnode;
    }
    temp->next=newnode;
}

void insertinmiddle(int data,int pos)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    node*temp=head;

    if(temp==NULL)
    {
        head=newnode;
        return;
    }

    int count=1;
    while(count<pos && temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        temp->next=newnode;
        //cout<<"Invalid Postion";
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;

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
        cin >> n;
        int data;
        for (int i = 0; i < n; i++)
        {
            cin>>data;
            insertAtBeg(data);
        }
        
        cout<<"Insert at Beginning: ";
        display();
        cout<<endl;
        head=NULL;
    }
    return 0;
}