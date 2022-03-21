#include<bits/stdc++.h>
using namespace std;


struct Stack{
    int *arr;
    int top;
    int cap;
    Stack(int c){
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x) {
        if(top==cap-1){
            cout << "Stack is full" <<endl; 
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop() {
        if(top == -1) 
            return INT_MIN;
        int res = arr[top];
        top--;
        return res;
    }
    int peek() {
        if(top == -1){
            return INT_MIN;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top+1;
    }
};


int main() {
    Stack S(10);
    s.push(10);
    s.push(9);
    cout << s.size() << s.peek() << s.isEmpty() << s.pop() << endl;

    return 0;
}