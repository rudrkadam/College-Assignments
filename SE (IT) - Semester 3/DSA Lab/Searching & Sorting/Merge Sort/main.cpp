#include <iostream>
using namespace std;

// merge function to merge two arrays in sorted order
void merge (int a[], int l, int m, int r)
{
    int i = l;
    int j = m+1;
    int k = l;
    int temp[r+1];

    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++)
    {
        a[p] = temp[p];
    }
}

// recursive mergeSort function
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    cout << "MERGE SORT ALGORITHM" << endl;

    // array declaration and input
    int n;
    cout << "Enter array length:";
    cin >> n;
    int array[n];
    cout << "Enter array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << endl;

    // sorting the array
    mergeSort(array, 0, n);

    // sorted array output
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
