#include <bits/stdc++.h>
using namespace std;

class dllnode 
{
    public:
    int data;
    dllnode *next,*prev;
    dllnode(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

class dll
{
public:
    dllnode *head;
    dll()
    {
        this->head = nullptr;
    }
    void insert_node_AtBeggining(int data)
    {
        dllnode *newnode = new dllnode(data);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = NULL;
            head->prev = newnode;
            head = newnode;
        }
    }
    void insert_node_atend(int data)
    {
        dllnode *newnode = new dllnode(data);
        dllnode *temp = head;
        if (temp == nullptr)
        {
            head = newnode;
        }
        else
        {
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    void insertnodetmiddle(int data, int pos)
    {
        dllnode *newnode = new dllnode(data);
        dllnode *temp = head;
        if (temp == nullptr)
        {
            head = newnode;
            return;
        }

        int count = 1;
        while (count < pos && temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = newnode;
            newnode->prev = temp;
            return;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        newnode->next->prev = newnode;
        temp->next = newnode;
    }
};

void display (dllnode *head)
{
    dllnode* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
