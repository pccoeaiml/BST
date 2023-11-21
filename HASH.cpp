#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;

class Employee {
public:
    int id;
    string name;

    Employee() : id(-1), name("") {}
    Employee(int empId, const string& empName) : id(empId), name(empName) {}
};

class HashTable {
private:
    Employee table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {}

    void addEmployee(const Employee& emp) {
        int index = hashFunction(emp.id);

        while (table[index].id != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = emp;
    }

    Employee* getEmployeeById(int empId) {
        int index = hashFunction(empId);

        while (table[index].id != -1) {
            if (table[index].id == empId) {
                return &table[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return nullptr;
    }
};

int main() {
    HashTable empHashTable;

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        int empId;
        string empName;

        cout << "Enter employee ID and name for employee " << i + 1 << ": ";
        cin >> empId >> empName;

        empHashTable.addEmployee(Employee(empId, empName));
    }

    int searchId;
    cout << "Enter the employee ID to search: ";
    cin >> searchId;

    Employee* foundEmployee = empHashTable.getEmployeeById(searchId);
    if (foundEmployee != nullptr) {
        cout << "Employee found: " << foundEmployee->name << endl;
    } else {
        cout << "Employee not found." << endl;
    }

    return 0;
}
