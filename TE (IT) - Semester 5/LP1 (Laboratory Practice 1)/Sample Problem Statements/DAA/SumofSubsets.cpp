#include <iostream>
#include <vector>
using namespace std;

// Function to find all subsets with a given sum using backtracking
void findSubsetsWithSum(vector<int> &arr, int index, int target, vector<int> &currentSubset, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(currentSubset);
        return;
    }

    if (index >= arr.size() || target < 0)
        return;

    // Include the current element in the subset
    currentSubset.push_back(arr[index]);
    findSubsetsWithSum(arr, index + 1, target - arr[index], currentSubset, result);

    // Exclude the current element from the subset
    currentSubset.pop_back();
    findSubsetsWithSum(arr, index + 1, target, currentSubset, result);
}

int main()
{
    int n;
    cout << "\nSUM OF SUBSETS (USING BACKTRACKING)" << endl;
    cout << "\nEnter the number of integers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> currentSubset;
    vector<vector<int>> result;

    findSubsetsWithSum(arr, 0, target, currentSubset, result);

    if (result.empty())
    {
        cout << "\nNo subsets found with the given sum." << endl;
    }
    else
    {
        cout << "\nSubsets with the sum " << target << " are:" << endl;
        for (const vector<int> &subset : result)
        {
            for (int num : subset)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
