#include <iostream>
#include <string>
using namespace std;

// Declaring array structure
struct Student
        {
    string name;
    int rollno;
    float sgpa;
        }SE;

// Function to print the array structure
void printDetails(Student SE[], int n)
{
    cout << "Roll No.\t" << "Name\t\t" << "SGPA" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << SE[i].rollno << "\t\t" << SE[i].name << "\t\t" << SE[i].sgpa << endl;
    }
}

// Sorting the array structure according to roll numbers using Bubble Sort
void bubbleSort(Student SE[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (SE[j].rollno > SE[j+1].rollno)
            {
                int temp = SE[j+1].rollno;
                SE[j+1].rollno = SE[j].rollno;
                SE[j].rollno = temp;
            }
        }
    }
}

// Sorting the array structure according to student names using Insertion Sort
void insertionSort(Student SE[], int n)
{
    for (int i = 1; i < n; i++)
    {
        string key1 = SE[i].name;
        int key2 = SE[i].rollno;
        float key3 = SE[i].sgpa;
        int j = i - 1;

        if (j >= 0 && SE[j].name > key1)
        {
            SE[j+1].name = SE[j].name;
            SE[j+1].rollno = SE[j].rollno;
            SE[j+1].sgpa = SE[j].sgpa;
            j = j - 1;
        }
        SE[j+1].name = key1;
        SE[j+1].rollno = key2;
        SE[j+1].sgpa = key3;
    }
}

// Sorting the array structure according to SGPA (finding out first ten toppers) using Quick Sort
int partition(Student *SE, int s, int e)
{
    float pivot = SE[e].sgpa;
    int pIndex = s;
    for (int i = s; i < e; i++)
    {
        if (SE[i].sgpa >= pivot)
        {
            string temp1 = SE[i].name;
            int temp2 = SE[i].rollno;
            float temp3 = SE[i].sgpa;

            SE[i].name = SE[pIndex].name;
            SE[i].rollno = SE[pIndex].rollno;
            SE[i].sgpa = SE[pIndex].sgpa;

            SE[pIndex].name = temp1;
            SE[pIndex].rollno = temp2;
            SE[pIndex].sgpa = temp3;

            pIndex++;
        }
    }
    string temp1 = SE[e].name;
    int temp2 = SE[e].rollno;
    float temp3 = SE[e].sgpa;

    SE[e].name = SE[pIndex].name;
    SE[e].rollno = SE[pIndex].rollno;
    SE[e].sgpa = SE[pIndex].sgpa;

    SE[pIndex].name = temp1;
    SE[pIndex].rollno = temp2;
    SE[pIndex].sgpa = temp3;

    return pIndex;
}
void quickSort(Student *SE, int s, int e)
{
    if (s < e)
    {
        int p = partition(SE, s, e);
        quickSort(SE, s, (p-1));
        quickSort(SE, (p+1), e);
    }
}

// Searching the array structure for given SGPA using Linear Search
void linearSearch (Student *SE, int n, float searchSGPA)
{
    int flag = 0;
    for (int i = 0; i<n; i++)
    {
        if(SE[i].sgpa == searchSGPA)
        {
            cout << SE[i].rollno << "\t\t" << SE[i].name << "\t\t" << SE[i].sgpa << endl;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "No such SGPA entry found." << endl;
    }
}

// Searching the array structure for given name using Binary Search
void binarySearch (Student *SE, int n, string searchName)
{
    int left = 0;
    int right = n;
    int flag = 0;

    while (left <= right)
    {
        int mid = (left + right)/2;
        if (SE[mid].name == searchName)
        {
            cout << SE[mid].rollno << "\t\t" << SE[mid].name << "\t\t" << SE[mid].sgpa << endl;
            flag = 1;
            break;
        }
        else if (SE[mid].name < searchName)
        {
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    if (flag == 0)
    {
        cout << "No such name entry found." << endl;
    }
}

int main()
{
    // Taking input for the array structure
    int n;
    cout << "Enter the number of students:";
    cin >> n;
    Student Database[n];
    cout << "Enter details (Name, Roll No., SGPA): " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Database[i].name;
        cin >> Database[i].rollno;
        cin >> Database[i].sgpa;
    }

    // Printing the array structure as entered
    cout << "\nEntered student details are as follows:" << endl;
    printDetails(Database, n);
    cout << endl;

    // Printing the sorted array structure according to roll no.
    bubbleSort(Database, n);
    cout << "a) Entered student details (in roll no. order):" << endl;
    printDetails(Database, n);
    cout << endl;

    // Printing the sorted array structure according to student name
    insertionSort(Database, n);
    cout << "b) Entered student details (in alphabetical order):" << endl;
    printDetails(Database, n);
    cout << endl;

    // Printing the sorted array structure according to SGPA (finding first 10 toppers)
    quickSort(Database, 0, n-1);
    cout << "c) Entered student details (in decreasing SGPA order):" << endl;
    if (n > 10)
    {
        printDetails(Database, 10);
    }
    else
    {
        printDetails(Database, n);
    }
    cout << endl;

    // Searching the array structure for given SGPA
    float searchSGPA;
    cout << "Enter the SGPA you want to search:";
    cin >> searchSGPA;
    cout << "d) Search result for SGPA:" << endl;
    linearSearch(Database, n, searchSGPA);
    cout << endl;

    // Searching the array structure for given name
    string searchName;
    cout << "Enter the name you want to search:";
    cin >> searchName;
    cout << "e) Search result for name:" << endl;
    binarySearch(Database, n, searchName);
    cout << endl;

    return 0;
}