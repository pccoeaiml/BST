#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data=value;
        next=nullptr;
    }
};
class Singly {
public:
    Node* head;
    Singly() {
        head=nullptr;
    }
    void insert(int value) {
        Node* newNode=new Node(value);
        if(head==nullptr) {
            head=newNode;
        }else{
            Node* current=head;
            while (current->next!=nullptr) {
                current=current->next;
            }
            current->next=newNode;
        }
    }
    void display() {
        Node* current = head;
        while(current != nullptr) {
            cout<<current->data << " ";
            current=current->next;
        }
        cout<<endl;
    }
    void search(int value) {
        Node* current=head;
        while (current!=nullptr) {
            if (current->data==value) {
                cout<<"Found: "<<current->data<< endl;
                return;
            }
            current=current->next;
        }
        cout<< "Not Found" <<endl;
    }
    void deleteNode(int value) {
        if (head==nullptr) {
            cout<< "Empty" << endl;
            return;
        }
        Node* prev=nullptr;
        Node* current=head;
        if (current!=nullptr && current->data==value) {
            head=current->next;
            delete current;
            return;
        }
        while (current!=nullptr && current->data!=value) {
            prev=current;
            current=current->next;
        }
        if (current==nullptr) {
            cout<< "Not Found" <<endl;
            return;
        }
        prev->next=current->next;
        delete current;
    }
    void reverse() {
        Node* prev=nullptr;
        Node* current=head;
        Node* next=nullptr;
        while (current!=nullptr) {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
};
int main() {
    Singly linkedList;
    int choice, value;
    do {
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Reverse\n6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value to insert: ";
                cin>>value;
                linkedList.insert(value);
                break;
            case 2:
                cout<<"Enter the value to delete: ";
                cin>>value;
                linkedList.deleteNode(value);
                break;
            case 3:
                cout<<"Enter the value to search: ";
                cin>>value;
                linkedList.search(value);
                break;
            case 4:
                cout<<"Linked List: ";
                linkedList.display();
                break;
            case 5:
                linkedList.reverse();
                break;
            case 6:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);
    return 0;
}