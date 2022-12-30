#include <iostream>
using namespace std;

int binarySearch (int a[], int n, int key)
{
    int left = 0;
    int right = n;

    while (left <= right)
    {
        int mid = (left + right)/2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    return -1;
}

bool sortedCheck(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (a[i] > a[i+1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the array length:";
    cin >> n;

    int a[n];
    cout << "Enter the array elements (IN ASCENDING ORDER):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int key;
    cout << "Enter the element to search:";
    cin >> key;

    if (sortedCheck(a, n))
    {
        int output = binarySearch(a, n, key);
        if (output == -1)
        {
            cout << "Element not found in the array.";
        }
        else
        {
            cout << "Element found at position: " << output+1 << " (Index: " << output << ")";
        }
    }
    else if (!sortedCheck(a, n))
    {
        cout << "Entered array is not sorted.";
    }

    return 0;
}
