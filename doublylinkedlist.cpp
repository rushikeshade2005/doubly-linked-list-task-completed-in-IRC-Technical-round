#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

Node*insertAtBeginning(Node*head, int newData)
{

    Node *newNode = new Node(newData);

    if (!head){
        newNode->next = newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;

        head = newNode;
    }

    return head;
}

void Display(Node *head){
    if (!head)
        return;
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->prev = head->next->next;

    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 45);
    head = insertAtBeginning(head,99);
    Display(head);

    return 0;
}
