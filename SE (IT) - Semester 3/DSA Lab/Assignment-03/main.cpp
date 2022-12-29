#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    // class constructor
    CircularQueue()
    {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    // method to check if the queue is empty
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // method to check if the queue is full
    bool isFull()
    {
        if ((rear+1)%5 == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // method to enqueue (insert) a value to the queue
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear+1)%5;
        }
        arr[rear] = val;
        itemCount++;
    }

    // method to dequeue (delete) a value from the queue
    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            itemCount--;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front+1)%5;
            itemCount--;
            return x;
        }
    }

    // method to count the no. of items in queue
    int count()
    {
        return (itemCount);
    }

    // method to print the queue
    void display()
    {
        cout << "Queue: ";
        if (rear > front)
        {
            for (int i = front; i < rear+1; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else if (rear == front)
        {
            if (rear == -1)
            {
                cout << "Queue is empty.";
            }
            else
            {
                cout << arr[front];
            }
        }
        else
        {
            for (int i = front; i < 5; i++)
            {
                cout << arr [i] << " ";
            }
            for (int i = 0; i < rear+1; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        cout << "Front: " << front << ", Rear: " << rear << endl;
    }
};

int main()
{
    CircularQueue q1;
    int option, value;

    do
    {
        cout << "\nEnter the option for the operation you want to perform:" << endl;
        cout << "1 - enqueue()" << endl;
        cout << "2 - dequeue()" << endl;
        cout << "3 - isEmpty()" << endl;
        cout << "4 - isFull()" << endl;
        cout << "5 - count()" << endl;
        cout << "6 - display()" << endl;
        cout << "0 - exit" << endl;

        cin >> option;

        switch (option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter a value to enqueue:";
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeued value is: " << q1.dequeue() << endl;
                break;
            case 3:
                if (q1.isEmpty())
                {
                    cout << "Queue is empty." << endl;
                }
                else
                {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                if (q1.isFull())
                {
                    cout << "Queue is full." << endl;
                }
                else
                {
                    cout << "Queue is not full." << endl;
                }
                break;
            case 5:
                cout << "Count of values in the queue is: " << q1.count() << endl;
                break;
            case 6:
                q1.display();
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
    while (option != 0);

    return 0;
}
