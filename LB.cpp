#include <iostream>
using namespace std;

class Search {
public:
    string name;
    string Number;

    int linear(Search arr[], int size, string target) {
        for (int i = 0; i < size; i++) {
            if (arr[i].name == target) {
                cout << "Contact Number: " << arr[i].Number << endl;
                return i;
            }
        }
        return -1;
    }

    int binary(Search arr[], int low, int high, string target, int size) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].name == target) {
                cout << "Contact Number: " << arr[mid].Number << endl;
                return mid;
            } else if (arr[mid].name < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << "Contact not found" << endl;
        return -1;
    }
};

int main() {
    int n;
    do {
        cout << "Enter the size of the array: ";
        cin >> n;
        if (n <= 0) {
            cout << "Size should be a positive integer. Please enter again." << endl;
        }
    } while (n <= 0);

    Search s[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the name: ";
        cin >> s[i].name;
        cout << "Enter the Number: ";
        cin >> s[i].Number;
    }

    cout << "Displaying the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i].name << "\t" << s[i].Number << endl;
    }

    string key;
    cout << "Enter the key: ";
    cin >> key;

    int choice;
    do {
        cout << "Enter the choice (1 for Linear Search, 2 for Binary Search): ";
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 1 && choice != 2);

    Search s1;

    switch (choice) {
        case 1:
            s1.linear(s, n, key);
            break;
        case 2:
            s1.binary(s, 0, n - 1, key, n);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    return 0;
}