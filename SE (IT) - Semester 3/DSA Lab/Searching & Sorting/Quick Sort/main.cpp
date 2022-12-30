#include <iostream>
using namespace std;

int partition(int a[], int s, int e)
{
    int pivot = a[e];
    int pIndex = s;
    for (int i = s; i < e; i++)
    {
        if (a[i] <= pivot)
        {
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = a[e];
    a[e] = a[pIndex];
    a[pIndex] = temp;
    return pIndex;
}

void quickSort(int a[], int s, int e)
{
    if (s < e)
    {
        int p = partition(a, s, e);
        quickSort(a, s, (p-1));
        quickSort(a, (p+1), e);
    }
}

int main()
{
    int n;
    cout << "Enter the array length:";
    cin >> n;

    int a[n];
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Entered array (unsorted) is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a, 0, n-1);
    cout << "Sorted array (using Quick Sort) is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
