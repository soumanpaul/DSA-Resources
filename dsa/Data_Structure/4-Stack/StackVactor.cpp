#include<bits/stdc++.h>
using namespace std;

struct Stack{
    vector<int> v;

    void push(int x) {
        v.push_back(x);
    }
    int pop() {
        int res = v.back();
        v.pop_back()
        return res;
    }
    int peek() {
        return v.back();
    }
    int size(){
        return v.size();
    }
    bool isEmpty() {
        return v.empty();
    }
};

int main() {
    Stack S;
    s.push(3);
    s.pop(3);
    s.size();
    s.peek();
    s.isEmpty();

    return 0;
}