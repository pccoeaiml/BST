#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted at the Front: " << value << endl;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted at the End: " << value << endl;
    }

    void deleteElement(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Search for the node with the given value
        do {
            if (temp->data == value) {
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        // If the value was not found
        if (temp == head && temp->data != value) {
            cout << "Not Found. Cannot delete." << endl;
            return;
        }

        // Unlink the node from the linked list
        if (temp == head && temp->next == head) {
            head = nullptr;
        } else if (temp == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = temp->next;
            prev->next = head;
        } else {
            prev->next = temp->next;
        }

        // Free the memory of the node
        delete temp;

        cout << "Deleted: " << value << endl;
    }

    void searchElement(int value) {
        Node* temp = head;
        do {
            if (temp->data == value) {
                cout << "Found: " << value << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found: " << value << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList circularLinkedList;

    int choice, value;

    do {
        cout << "\n1. Insert at Front\n2. Insert at End\n3. Delete Element\n4. Search Element\n5. Display List\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at front: ";
                cin >> value;
                circularLinkedList.insertFront(value);
                break;

            case 2:
                cout << "Enter the value to insert at end: ";
                cin >> value;
                circularLinkedList.insertEnd(value);
                break;

            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                circularLinkedList.deleteElement(value);
                break;

            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                circularLinkedList.searchElement(value);
                break;

            case 5:
                circularLinkedList.display();
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
