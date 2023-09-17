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



class Queue
{
private:
    Node* head;
public:
    Queue()
    {
        head = nullptr;
    }

    void enqueue(int x)
    {
        Node* newNode = new Node(x);
        if(head == nullptr) head = newNode;
        else
        {
            Node* p = head;
            while(p->next != nullptr)
            {
                p = p->next;
            }
            p->next = newNode;
        }
    }

    void dequeue()
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
};

int main(){
    Queue listt;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "enqueue")
        {
            int x;
            cin >> x;
            listt.enqueue(x);
        }
        else if(cmd == "dequeue")
        {
            listt.dequeue();
        }
    }
    listt.printList();
}
