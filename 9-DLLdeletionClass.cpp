#include <bits/stdc++.h>
using namespace std;

class sllnode 
{
    public:
    int data;
    sllnode *next,*prev;
    sllnode(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

class dll
{
    public:
    sllnode *head;
    dll()
    {
        this->head=nullptr;
    }
   void deletenodebegin()
    {
        sllnode *temp=head;
        if(temp==NULL)
        {
         cout<<"Linked list is empty"<<endl;
         return;
        }
        head=head->next;
        free(temp);
    } 

    void deletenodeatend()
    {
         sllnode *temp=head;
        if(temp==NULL)
        {
         cout<<"Linked list is empty"<<endl;
         return;
        }
        if(temp->next==NULL)
        {
            head=NULL;
            free(temp);
            return;
        }
        while(temp->next->next!=NULL) //  to reach to the second last node 
        {
            temp=temp->next;
        }
        sllnode *temp1=temp->next;
        temp1=temp->next;
        temp->next=NULL;
        free(temp1);
    }

    void deleteinmid(int pos){
         sllnode *temp=head;
        if(temp==NULL)
        {
         cout<<"Linked list is empty"<<endl;
         return;
        }
        if(temp->next==NULL)
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
        sllnode* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        free(temp1);
    }
};

void display (sllnode *head)
{
    sllnode* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
    }
}


