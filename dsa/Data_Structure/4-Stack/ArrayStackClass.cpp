#include<bits/stdc++.h>
using namespace std;
#defined MAX 100;

 
class Stack {
    int top;
    public :
        int aStack[MAX];

        Stack() { top=-1;}
        bool push(int item);
        int pop();
        bool isEmpty();
}

bool Stack::push(int x){
    if(top >= (MAX-1)) return false;
    else {
        a[++top] = x;
        return true
    }
}

int Stack::pop(){
    if(top < 0) return 0;
    else {
        int x = a[top--];
        return x;
    }
}

bool isEmpty(){
    return (top <0);
}



int main() {
    class Stack s;
    s.push(5);
    s.push(10);

    s.pop()

    return 0;
}