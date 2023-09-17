#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};



class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertNode(int pos, int x)
    {
        Node* newNode = new Node(x);
        if(pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            if(head != nullptr)
            {
                Node* p = head;
                for(int i = 0; i < pos - 1; i++)
                {
                    p = p->next;
                }
                newNode->next = p->next;
                p->next = newNode;
            }
        }
    }

    void deleteNode(int pos)
    {
        Node* p = head;
        int len = 0;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        if(pos >= 0 && pos < len)
        {
            if(pos == 0)
            {
                Node* tmp = head;
                head = head->next;
                delete (tmp);
            }
            else //(pos < len-1)
            {
                p = head;
                for(int i = 0; i < pos-1; i++)
                {
                    p = p->next;
                }
                Node* tmp = p->next;
                p->next = p->next->next;
                delete (tmp);
            }
        }
    }

    void printList()
    {
        Node* p = head;
        while(p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
    }
};

int main(){
    LinkedList llist;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "insert")
        {
            int pos, x;
            cin >> pos >> x;
            llist.insertNode(pos, x);
        }
        else if(cmd == "delete")
        {
            int pos;
            cin >> pos;
            llist.deleteNode(pos);
        }
    }
    llist.printList();
}
