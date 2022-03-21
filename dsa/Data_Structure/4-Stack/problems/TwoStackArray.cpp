#include<bits/stdc++.h>
usina namespace std;

struct TwoStack {
    int* arr;
    int cap;
    int top1, top2;

    TwoStack(int n) {
        cap = n;
        arr = new int[n];
        top = -1;
        top2 = cap;
    }
    void push1(int x){
        if(top1 < top2 -1){
            top1++;
            arr[top1] = x;
        }else {
            exit(1);
        }
    }
    void push2(int x) {
        if(top1 < top2-1){
            top2--;
            arr[top2] = x;
        } else {
            exit(1);
        }
    }
    int pop1() {
        if(top1 >= 0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else {
            exit(1);
        }
    }
    int pop2(){
        if(top2 < cap){
            int x = arr[top2];
            top2--;
            return x;
        }
        else {
            exit(1);
        }
    }
}


int main() {
    TwoStack ts(10);
    ts.push1(5);
    ts.push2(4);
}