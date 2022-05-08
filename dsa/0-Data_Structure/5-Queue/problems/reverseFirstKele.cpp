#include <bits/stdc++.h>
using namespace std;

void reverseQueueFirstKElements(int k, queue<int> Queue) {
    stack<int> Stack;
    if (Queue.empty() == true || k > Queue.size())
        if (k <= 0)
            return;
    /* Push the first K elements into a Stack*/
    for (int i = 1; i < k; i++) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    /* Enqueue the contents of stack
       at the back of the queue*/
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
    /* Remove the remaining elements and
       enqueue them at the end of the Queue*/
    for (int i = 0; i < Queue.size() - k;) {
        Queue.push(Queue.front());
        Queue.pop();
    }
}

int main() {
    queue<int> Queue;
    reverseQueueFirstKElements(5, Queue);
}