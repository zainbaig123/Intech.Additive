
#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    stack<int> s;
    int minEle;

    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";

        else
            cout << "Minimum Element in the stack is: "
                 << minEle << "\n";
    }

    void peek()
    {
        if (s.empty())
        {
            cout << "Stack is empty ";
            return;
        }

        int t = s.top();

        cout << "Top Most Element is: ";

        (t < minEle) ? cout << minEle : cout << t;
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();

        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2 * minEle - t;
        }

        else
            cout << t << "\n";
    }

    void push(int x)
    {

        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }

        else if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }

        else
            s.push(x);

        cout << "Number Inserted: " << x << "\n";
    }
};

int main()
{
    MyStack s;

    int k;
    while (1)
    {
        cout << endl
             << "Press 1 For Push in Stack " << endl
             << "Press 2 for pop in Stack" << endl
             << "Press 3 for get min of stack " << endl
             << "press 4 for peek the stack" << endl
             << "press 5 for End the code " << endl;
        cin >> k;

        switch (k)
        {
        case 1:
            int p;
            cout << "Enter the no to push";
            cin >> p;
            s.push(p);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.getMin();
            break;
        case 4:
            s.peek();
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Sorry wrong entry try again";
        }
    }
    return 0;
}
