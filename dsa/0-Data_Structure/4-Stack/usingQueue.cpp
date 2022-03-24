// Let stack to be implemented be 's' and queues used to implement be 'q1' and 'q2'.

// C++ pogram to implement a stack using 
// two queues
#include<bits/stdc++.h>

using namespace std;

// Stack class
class Stack
{ 
    // Two inbuilt queues
    queue<int> q1, q2;
    
    // To maintain current number of
    // elements
    int curr_size;

    public:
    Stack()
    {
        curr_size = 0;
    }

    // Function to implement push() operation
    void push(int x)
    {
        curr_size++;

        // Push x first in empty q2
        q2.push(x);

        // Push all the remaining 
        // elements in q1 to q2. 
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    // Function to implement pop() operation
    void pop(){

        // if no elements are there in q1 
        if (q1.empty())
            return ;
        q1.pop();
        curr_size--;
    }

    // Function to return top element
    // of implemented Stack
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    // Function to return size of stack
    int size()
    {
        return curr_size;
    }
};

// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() 
        << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size() 
        << endl;
    return 0;
}
