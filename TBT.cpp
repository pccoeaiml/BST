#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int value) : data(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

class TBT {
public:
    Node* root;

    TBT() : root(nullptr) {}

    Node* createNode(int value) {
        return new Node(value);
    }

    void insert(int value) {
        Node* newNode = createNode(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            while (true) {
                if (value < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        newNode->right = current;
                        newNode->isThreaded = true;
                        break;
                    } else {
                        current = current->left;
                    }
                } else if (value > current->data) {
                    if (current->right == nullptr || current->isThreaded) {
                        newNode->right = current->right;
                        current->right = newNode;
                        current->isThreaded = false;
                        newNode->isThreaded = true;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    Node* leftmost(Node* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void threadedInorder() {
        Node* current = leftmost(root);
        while (current != nullptr) {
            cout << current->data << " ";
            if (current->isThreaded) {
                current = current->right;
            } else {
                current = leftmost(current->right);
            }
        }
        cout << endl;
    }

    Node* search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return current;
            } else if (value < current->data) {
                current = current->left;
            } else {
                if (current->isThreaded) {
                    break;
                }
                current = current->right;
            }
        }
        return nullptr;
    }
};

int main() {
    TBT threadedBinaryTree;

    int choice, value;

    do {
        cout << "\n1. Insert\n2. Threaded Inorder Traversal\n3. Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                threadedBinaryTree.insert(value);
                break;

            case 2:
                cout << "Threaded Inorder Traversal: ";
                threadedBinaryTree.threadedInorder();
                break;

            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                if (threadedBinaryTree.search(value) != nullptr) {
                    cout << "Found: " << value << endl;
                } else {
                    cout << "Not Found: " << value << endl;
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
