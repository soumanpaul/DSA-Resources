// implementation of K Stacks in an array

#include <bits/stdc++.h>
using namespace std;

struct kStacks {

    int *arr;
    int *top;
    int *next;
    int cap, k;
    int freeTop;

    kStacks(int k1, int n) {
        k = k1;
        cap = n;
        arr = new int[cap];
        top = new int[k];
        next = new int[cap];

        for (int i = 0; i < k; i++)
            top[i] = -1;
        freeTop = 0;
        for (int i = 0; i < cap - 1; i++)
            next[i] = i + 1;
        next[cap - 1] = -1;
    }

    bool isFull() { return freeTop == -1; }

    bool isEmpty(int sn) { return top[sn] == -1; }

    void push(int x, int sn) {
        if (isFull())
            return;
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn) {
        if (isEmpty(sn)) {
            return INT_MAX;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};

int main() {
    int k = 4, n = 20;

    kStacks ks(k, n);
}