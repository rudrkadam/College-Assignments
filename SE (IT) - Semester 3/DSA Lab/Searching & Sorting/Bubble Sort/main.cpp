#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    int rounds = 0;
    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
        int flag = false;       // to check if swapping was actually done or not
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                flag = true;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                count++;
            }
        }
        if (flag == true)       // this 'i' round contributed in sorting (swapping)
        {
            rounds++;
        }
        else                    // this 'i' round did not contribute in sorting (no swapping was done)
        {
            break;
        }
    }
    cout << "\nNo. of rounds required to sort: " << rounds << endl;
    cout << "No. of swaps required to sort: " << count << endl;
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

    cout << "\nEntered array (unsorted) is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    bubbleSort(a, n);
    cout << "\nSorted array (using Bubble Sort) is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
