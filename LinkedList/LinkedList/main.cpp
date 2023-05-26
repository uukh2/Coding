#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
class linkedlist
{
    node* head;
public:
    linkedlist()
    {
        head=NULL;
    }

    bool isempty()
    {
        return head==NULL;
    }

    bool isfound(int val)
    {
        node* temp = head;
        bool found = false;
        while(temp!=NULL)
        {
            if(temp->data==val)return true;
            temp = temp->next;
        }
        return false;
    }

    void insert_ele(int val)
    {
        node* newnode = new node;
        newnode->data = val;
        if(isempty())
        {
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void delete_ele(int val)
    {
        node* delptr1 = head;
        node* delptr2 = head;
        if(isempty())
        {
            cout<<"List is Empty."<<'\n';
            return;
        }
        if(!isfound(val))
        {
            cout<<"This element is not found in this list."<<'\n';
            return;
        }
        if(head->data==val)head = head->next;
        else
        {
            while(delptr1->data!=val)
            {
                delptr2 = delptr1;
                delptr1 = delptr1->next;
            }
            delptr2->next = delptr1->next;
        }
        delete(delptr1);
    }

    int counter()
    {
        node* temp = head;
        int counter=0;
        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        return counter;
    }

    void display()
    {
        if(isempty())
        {
            cout<<"";
            return;
        }
        else
        {
            cout<<"This is elements in Linkedlist : [ ";
            node* temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"].\n";
        }
    }

};
int main()
{
    linkedlist l;
    int val,num;
    for(int i=0; i<4; i++)
    {
        cout<<"enter a number "<<i+1<<" : ";
        cin>>val;
        l.insert_ele(val);
    }
    cout << "Enter element to be delete : ";
    cin>>num;
    l.delete_ele(num);
    l.display();
    cout<<"the number of elements = "<<l.counter()<<'\n';
    return 0;
}
