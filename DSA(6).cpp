#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int v)
    {
        data = v;
        next = nullptr;
        prev = nullptr;
    }
};

class Dequeue
{
public:
    int size;
    Node *front;
    Node *rear;
    Dequeue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    int isEmpty()
    {
        return size == 0;
    }

    void EnqueueFront(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            rear = front = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void EnqueueRear(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            rear = front = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        Node *temp = front;
        front = front->next;
        if (front)
        {
            front->prev = nullptr;
        }
        else
        {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        Node *temp = rear;
        rear = rear->prev;
        if (rear)
        {
            rear->next = nullptr;
        }
        else
        {
            front = nullptr;
        }
        delete temp;
        size--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No display " << endl;
        }
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data<<" ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Dequeue q;
    int choice;
    char add;
    while (true)
    {
        cout << "1.EnqueueFront\n2.EnqueueRear\n3.DeleteFront\n4.DeleteRear\n5.display\n6.Exit " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter value : ";
            cin >> value;
            q.EnqueueFront(value);
            break;
        case 2:
            int data;
            cout << "Enter value :";
            cin >> data;
            q.EnqueueRear(data);
            break;
        case 3:
            q.deleteFront();
            break;
        case 4:
            q.deleteRear();
            break;
        case 5:
            q.display();
            break;
        case 6:
            cout << "Exit ";
            break;
        }
    }
    return 0;
}