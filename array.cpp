#include<iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

class TwoDimensionalArray {
private:
    int matrix[MAX_ROWS][MAX_COLS];
    int numRows, numCols;

public:
    TwoDimensionalArray() : numRows(0), numCols(0) {}

    void insert() {
        cout << "Enter the number of rows: ";
        cin >> numRows;

        cout << "Enter the number of columns: ";
        cin >> numCols;

        cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cout << "Enter element at position (" << i << ", " << j << "): ";
                cin >> matrix[i][j];
            }
        }
    }

    void display() {
        cout << "Matrix elements:\n";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void search(int value) {
        bool found = false;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (matrix[i][j] == value) {
                    cout << "Element " << value << " found at position (" << i << ", " << j << ").\n";
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Element " << value << " not found in the matrix.\n";
        }
    }

    void findMinAndMax() {
        int minElement = matrix[0][0];
        int maxElement = matrix[0][0];

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                }
                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                }
            }
        }

        cout << "Minimum element: " << minElement << endl;
        cout << "Maximum element: " << maxElement << endl;
    }
};

int main() {
    TwoDimensionalArray matrix;

    int choice, value;

    do {
        cout << "\n1. Insert Matrix\n2. Display Matrix\n3. Search Element\n4. Find Min and Max\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                matrix.insert();
                break;

            case 2:
                matrix.display();
                break;

            case 3:
                cout << "Enter the element to search: ";
                cin >> value;
                matrix.search(value);
                break;

            case 4:
                matrix.findMinAndMax();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}
