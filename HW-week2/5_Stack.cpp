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



class Stack
{
private:
    Node* head;

    void printReverseList(Node* top)
    {
        Node* p = top;
        if(p == nullptr) return;
        printReverseList(p->next);
        cout << p->data << " ";
    }
public:
    Stack()
    {
        head = nullptr;
    }

    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if(head == nullptr) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
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
    void printReverseStack()
    {
        printReverseList(head);
        cout << "\n";
    }
};



int main(){
    Stack stackk;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "push")
        {
            int x;
            cin >> x;
            stackk.push(x);
        }
        else if(cmd == "pop")
        {
            stackk.pop();
        }
    }
    stackk.printList();
    stackk.printReverseStack();
}
