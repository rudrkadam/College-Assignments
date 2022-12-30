#include <iostream>
using namespace std;

void linearSearch(int a[], int n, int key)
{
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Element found at position: " << i+1 << " (Index: " << i << ")";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Element not found in the array.";
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

    int key;
    cout << "Enter the element to search:";
    cin >> key;
    linearSearch(a, n, key);

    return 0;
}
