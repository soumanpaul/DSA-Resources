#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack {
    int top;
    int *arraystack;

public:
    Stack(int size) {
        top = -1;
        arraystack = new int(size);
    }
    ~Stack() {
        delete arraystack;
    }
    bool push(int item);
    int pop();
    bool isEmpty();
    int peek();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1))
        return false;
    else {
        arraystack[++top] = x;
        return true;
    }
}

int Stack::pop() {
    if (top < 0)
        return 0;
    else {
        int x = arraystack[top--];
        return x;
    }
}
int Stack::peek() {
    return top;
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack stak(20);
    stak.push(5);
    stak.push(10);

    int item = stak.pop();
    cout << "Deleted item :" << item;
    return 0;
}