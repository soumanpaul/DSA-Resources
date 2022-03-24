#include <bits/stdc++.h>
using namespace std;
class MyStack {
    queue<int> q1, q2;
    int curr_size;

public:
    MyStack() {
        curr_size = 0;
    }
    void push(int x) {
        curr_size++;
        q1.push(x);
        int size = q1.size();
        while (size > 1) {
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
            size--;
        }
    }

    int pop() {
        if (q1.empty())
            return false;
        int itm = q1.front();
        q1.pop();
        curr_size--;
        return itm;
    }

    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */