#include <iostream>
using namespace std;
class ArrayQueue
{
    int arr[10], last;

public:
    void enqueue(int);
    int dequeue();
    ArrayQueue()
    {
        last = 0;
    }
};

void ArrayQueue::enqueue(int a)
{
    arr[last++] = a;
    cout << arr[last - 1] << " enqueued at " << last - 1 << endl;
}
int ArrayQueue::dequeue()
{
    if (last >= 0)
    {
        return arr[--last];
    }
    else
    {
        return NULL;
    }
}
main()
{
    ArrayQueue i;
    int s, a;
    while (1)
    {
        cout << "PRESS 1 FOR ENQUEUE\n"
                "PRESS 2 FOR DEQUEUE"
             << endl;
        cout << "PRESS 0 TO END" << endl;
        cin >> s;
        if (s == 1)
        {
            cout << "give the integer to enqueue" << endl;
            cin >> a;
            i.enqueue(a);
        }
        else if (s == 2)
        {
            a = i.dequeue();
            if (a != NULL)
            {
                cout << a << " has been dequeued" << endl;
            }
            else
            {
                cout << "INVALID REQUEST" << endl;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}