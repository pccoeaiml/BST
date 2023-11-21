
#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee
{
    string name;
    double salary;

    Employee() : name(""), salary(0.0) {}

    Employee(string empName, double empsalary)
    {
        name = empName;
        salary = empsalary;
    }
};

void swap(Employee &a, Employee &b)
{
    Employee temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Employee arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j].salary > arr[j + 1].salary)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(Employee arr[], int low, int high)
{
    double pivot = arr[low].salary;
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (arr[i].salary < pivot && i <= high)
        {
            i++;
        }
        while (arr[j].salary > pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(Employee arr[], int low, int high)
{
    if (low <= high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void insertionSort(Employee arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        Employee key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].salary > key.salary)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void displayTopFive(const Employee arr[], int n)
{
    cout << "\nDetails of the top five employees with the highest salary:\n";
    for (int i = n - 1; i >= max(0, n - 5); --i)
    {
        cout << "Employee " << n - i << ": Name: " << arr[i].name << ", Salary: $" << arr[i].salary << endl;
    }
}

int main()
{
    Employee employeeArray[MAX_EMPLOYEES];
    int numEmployees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i)
    {
        string empName;
        double empSalary;

        cout << "Enter the name and monthly salary for employee " << i + 1 << ": ";
        cin >> empName >> empSalary;

        employeeArray[i] = Employee(empName, empSalary);
    }

    Employee bubbleSortArray[MAX_EMPLOYEES];
    for (int i = 0; i < numEmployees; ++i)
    {
        bubbleSortArray[i] = employeeArray[i];
    }
    bubbleSort(bubbleSortArray, numEmployees);

    Employee quickSortArray[MAX_EMPLOYEES];
    for (int i = 0; i < numEmployees; ++i)
    {
        quickSortArray[i] = employeeArray[i];
    }
    quickSort(quickSortArray, 0, numEmployees - 1);

    Employee insertionSortArray[MAX_EMPLOYEES];
    for (int i = 0; i < numEmployees; ++i)
    {
        insertionSortArray[i] = employeeArray[i];
    }
    insertionSort(insertionSortArray, numEmployees);

    displayTopFive(bubbleSortArray, numEmployees);

    displayTopFive(quickSortArray, numEmployees);

    displayTopFive(insertionSortArray, numEmployees);

    return 0;
}
