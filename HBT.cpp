#include<iostream>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    int height;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1; 
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    Node* insert(Node* root, int value);
    bool search(Node* root, int value);
    void displayInOrder(Node* root);
    int getHeight(Node* root);
    int getBalanceFactor(Node* root);
    Node* LL(Node* parent);
    Node* RR(Node* parent);
    Node* LR(Node* parent);
    Node* RL(Node* parent);
};

int AVL::getHeight(Node* root) {
    return (root == nullptr) ? 0 : root->height;
}

int AVL::getBalanceFactor(Node* root) {
    return (root == nullptr) ? 0 : getHeight(root->left) - getHeight(root->right);
}

Node* AVL::insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
  
        return root;
    }

  
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

  
    if (balance > 1) {
        if (value < root->left->data) {
            return LL(root);
        } else {
            return LR(root);
        }
    } else if (balance < -1) {
        if (value > root->right->data) {
            return RR(root);
        } else {
            return RL(root);
        }
    }

    return root;
}

bool AVL::search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void AVL::displayInOrder(Node* root) {
    if (root != nullptr) {
        displayInOrder(root->left);
        cout << root->data << " ";
        displayInOrder(root->right);
    }
}

Node* AVL::LL(Node* parent) {
    Node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent->height = getHeight(parent);
    temp->height = getHeight(temp);
    return temp;
}

Node* AVL::RR(Node* parent) {
    Node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent->height = getHeight(parent);
    temp->height = getHeight(temp);
    return temp;
}

Node* AVL::LR(Node* parent) {
    parent->left = RR(parent->left);
    return LL(parent);
}

Node* AVL::RL(Node* parent) {
    parent->right = LL(parent->right);
    return RR(parent);
}

int main() {
    AVL tree;
    int choice, value;
    char cont;

    do {
        cout << "Choose an operation:\n1. Insert a node\n2. Search a node\n3. Display in ascending order\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                tree.root = tree.insert(tree.root, value);
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> value;
                if (tree.search(tree.root, value)) {
                    cout << "Node found.\n";
                } else {
                    cout << "Node not found.\n";
                }
                break;
            case 3:
                cout << "Ascending order: ";
                tree.displayInOrder(tree.root);
                cout << endl;
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
