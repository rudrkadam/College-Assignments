#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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

    selectionSort(a, n);
    cout << "Sorted array (using Selection Sort) is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
