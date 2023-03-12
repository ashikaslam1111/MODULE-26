#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node* prev;
};
class dequee
{
public:
    node* head;
    node* tail;
    int sz;
    dequee()
    {
        sz=0;
        head=NULL;
        tail=NULL;
    }
    node* creatNewNode(int value)
    {
        node* newnode=new node;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }

    void pushBack(int value)
    {
        node* a= creatNewNode(value);
        if(sz==0)
        {
            head=a;
            tail=a;
        }
        tail->next=a;
        a->prev=tail;
        tail=a;
        sz++;
    }

    void pushFront(int value)
    {
        sz++;
        node* a= creatNewNode(value);
        if(sz==0)
        {
            head=a;
            tail=a;
            sz++;
            return;
        }
        a->next=head;
        head->prev=a;
        head=a;
        sz++;
    }

    void popFront()
    {
        if(sz==0)return;

        if(sz==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node* a=head;
        a->next->prev=NULL;
        head= a->next;
        delete a;
        sz--;
    }

    void popBack()
    {
        if(sz==0)return;
        sz--;
        if(sz==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            return;
        }
        node* a=tail;
        a->prev->next=NULL;
        tail= a->prev;
        delete a;
    }

    int Size()
    {
        return sz;
    }
    int Front()
    {
        if(sz==0)return -1000;
        return head->data;
    }
    int Back()
    {
        if(sz==0)return -1000;
        return tail->data;
    }
};
int main()
{
    dequee d;
    d.pushBack(12);
    d.pushFront(7);
    d.pushBack(2);

    cout<<d.Front();
    return 0;
}
