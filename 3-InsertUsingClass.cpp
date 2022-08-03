#include <bits/stdc++.h>
using namespace std;

class sllnode 
{
    public:
    int data;
    sllnode *next;
    sllnode(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

class sll
{
    public:
    sllnode *head;
    sll()
    {
        this->head=nullptr;
    }
    void insert_node_AtBeggining(int data)
    {
        sllnode *newnode = new sllnode(data);
        if(head==nullptr)
        {
            head=newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    void insert_node_atend(int data)
    {
        sllnode *newnode = new sllnode(data);
        sllnode*temp=head;
        if(temp==nullptr)
        {
           head=newnode;
        }
        else{
            while(temp->next!=nullptr) temp = temp->next;
           
            temp->next=newnode;
        }
    }
    void insertnodetmiddle(int data,int pos)
    {
        sllnode *newnode = new sllnode(data);
        sllnode*temp=head;
         if(temp==nullptr)
         {
             head==newnode;
         }
         else
         {
             int count=1;
             while(count<pos)
             {
                 count++;
                 temp=temp->next;
             }
             newnode->next=temp->next;
             temp->next=newnode;
         }
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
        sll *llist = new sll(); //in every testcase a new list is 
                                //created so no need to make head=null
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            llist->insert_node_AtBeggining(data);
        }
        cout<<"Linked list after insert at beginning: ";
        display(llist->head);

        sll*slist=new sll();
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            slist->insert_node_atend(data);
        }
        cout<<"Linked list after insert at beginning: ";
        display(slist->head);

        int pos;
        cin>>pos;
        int data;
        cin>>data;
        cout<<"insert after in llist: ";
        llist->insertnodetmiddle(data,pos);
        display(llist->head);
        cout<<"insert after in slist: ";
        slist->insertnodetmiddle(data,pos);
        display(slist->head);

    }
    return 0;
}

