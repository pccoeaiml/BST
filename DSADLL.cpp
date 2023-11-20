#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted at the Front: " << value << endl;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        cout << "Inserted at the End: " << value << endl;
    }

    void deleteElement(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head;

        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Not Found. Cannot delete." << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;

        cout << "Deleted: " << value << endl;
    }

    void searchElement(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Found: " << value << endl;
                return;
            }
            current = current->next;
        }
        cout << "Not Found: " << value << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Doubly Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList doublyLinkedList;

    int choice, value;

    do {
        cout << "\n1. Insert at Front\n2. Insert at End\n3. Delete Element\n4. Search Element\n5. Display List\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at front: ";
                cin >> value;
                doublyLinkedList.insertFront(value);
                break;

            case 2:
                cout << "Enter the value to insert at end: ";
                cin >> value;
                doublyLinkedList.insertEnd(value);
                break;

            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                doublyLinkedList.deleteElement(value);
                break;

            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                doublyLinkedList.searchElement(value);
                break;

            case 5:
                doublyLinkedList.display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}
