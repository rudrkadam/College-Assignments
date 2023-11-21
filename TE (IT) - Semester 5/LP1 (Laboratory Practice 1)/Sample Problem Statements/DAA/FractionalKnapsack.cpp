// Fractional Knapsack

#include <iostream>
using namespace std;

// Structure for Item
struct Item
{
    int no;
    float weight, price, pwratio;
};

// Bubble Sort
void bubbleSort(Item item[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (item[j].pwratio < item[j + 1].pwratio)
            {
                Item temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

int main()
{
    cout << "---- FRACTIONAL KNAPSACK PROGRAM ----" << endl;

    int bagCapacity;
    cout << "\nEnter bag capacity (weight it can carry): ";
    cin >> bagCapacity;

    int itemCount;
    cout << "\nEnter the number of items available: ";
    cin >> itemCount;

    Item item[itemCount];

    cout << "\nEnter item weight and price (seperated by space):" << endl;
    for (int i = 0; i < itemCount; i++)
    {
        cout << "- item " << i + 1 << ": ";
        item[i].no = i + 1;
        cin >> item[i].weight;
        cin >> item[i].price;
        item[i].pwratio = item[i].price / item[i].weight;
    }

    // Printing entered items in a tabular form
    cout << "\n⇒ DISPLAYING THE ENTERED ITEMS:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Item No. \t| Weight \t| Price \t| P/W Ratio" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < itemCount; i++)
    {
        cout << item[i].no << "\t\t| " << item[i].weight << "\t\t| " << item[i].price << "\t\t| " << item[i].pwratio << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    // Sorting the items in the descending order of their P/W ratio and then printing them in a tabular form
    bubbleSort(item, itemCount);
    cout << "\n⇒ DISPLAYING THE SORTED ITEM LIST:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Item No. \t| Weight \t| Price \t| P/W Ratio" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < itemCount; i++)
    {
        cout << item[i].no << "\t\t| " << item[i].weight << "\t\t| " << item[i].price << "\t\t| " << item[i].pwratio << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    // Calculation for the last (fraction) item in the bag
    float totalProfit = 0;
    Item lastItem;
    int finalItemCout = 0;
    float fraction;
    for (int i = 0; i < itemCount; i++)
    {
        int endPoint = bagCapacity;
        bagCapacity = bagCapacity - item[i].weight;
        if (bagCapacity >= 0)
        {
            totalProfit = totalProfit + item[i].price;
        }
        else
        {
            finalItemCout = i + 1;
            lastItem.no = item[i].no;
            lastItem.weight = endPoint;
            lastItem.price = item[i].price * (endPoint / item[i].weight);
            fraction = endPoint / item[i].weight;
            totalProfit = totalProfit + lastItem.price;
            lastItem.pwratio = item[i].pwratio;
            break;
        }
    }

    cout << "\n⇒ Total Profit of the Bag = " << totalProfit << endl;

    cout << "\n⇒ DISPLAYING THE ITEM LIST IN BAG (* = fractional item):" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Item No. \t| Weight \t| Price \t| P/W Ratio" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < finalItemCout - 1; i++)
    {
        cout << item[i].no << "\t\t| " << item[i].weight << "\t\t| " << item[i].price << "\t\t| " << item[i].pwratio << endl;
    }
    cout << lastItem.no << "*" << "\t\t| " << lastItem.weight << "\t\t| " << lastItem.price << "\t\t| " << lastItem.pwratio << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "(fraction = " << fraction << ")\t\t  Total Profit = " << totalProfit << "\n" << endl;

    return 0;
}