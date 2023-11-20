
#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }

    void remove(int value) {
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        while (current != nullptr && current->data != value) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current == nullptr) {
            return;
        }

        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete current;
        } else if (current->left == nullptr || current->right == nullptr) {
            TreeNode* child = (current->left != nullptr) ? current->left : current->right;
            if (current == root) {
                root = child;
            } else if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            delete current;
        } else {
            TreeNode* successor = getSuccessor(current);
            current->data = successor->data;
            remove(successor->data);
        }
    }

    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* parent = node;
        TreeNode* successor = node;
        TreeNode* current = node->right;

        while (current != nullptr) {
            parent = successor;
            successor = current;
            current = current->left;
        }

        if (successor != node->right) {
            parent->left = successor->right;
            successor->right = node->right;
        }

        return successor;
    }

    bool search(int value) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    void displayInorder() {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                cout << current->data << " ";
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    cout << current->data << " ";
                    current = current->right;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    while (true) {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display Inorder\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.remove(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << value << " is in the tree." << endl;
                } else {
                    cout << value << " is not in the tree." << endl;
                }
                break;
            case 4:
                cout << "Inorder traversal: ";
                bst.displayInorder();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
