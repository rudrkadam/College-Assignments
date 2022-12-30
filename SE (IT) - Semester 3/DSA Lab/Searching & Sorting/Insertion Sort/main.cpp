#include <iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        if (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}

int main()
{
    int n;
    cout << "Enter the array length:";
    cin >> n;

    int a[n];
    cout << "Enter the array elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Entered array (unsorted) is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    insertionSort(a, n);
    cout << "Sorted array (using Insertion Sort) is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
