#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};



class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList()
    {
        head = new Node(NULL);
        tail = new Node(NULL);
        head->next = tail;
        tail->prev = head;
    }

    void addLast(int val)
    {
        Node* newNode = new Node(val);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }

    void count_triplets()
    {
        Node* p = head->next;
        int len = 0;
        while(p != tail)
        {
            len++;
            p = p->next;
        }
        if(len < 3)
        {
            cout << "0";
            return;
        }
        int countTriplets = 0;
        p = head->next->next;
        while(p->next != tail)
        {
            int a, b, c;
            a = p->prev->data;
            b = p->data;
            c = p->next->data;
            if(a+b+c == 0) countTriplets++;
            p = p->next;
        }
        cout << countTriplets;
    }

    void printList()
    {
        Node* p = head->next;
        while(p != tail)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
    }
};

int main()
{
    int n; cin >> n;
    DoublyLinkedList llist;
    for(int i = 0; i < n; i++)
    {
        int val; cin >> val;
        llist.addLast(val);
    }
    llist.count_triplets();
}
