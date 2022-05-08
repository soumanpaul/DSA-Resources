#include <bits/stdc++.h>
using namespace std;

// O(3n) O(2n) space
int getMaxArea(int arr[], int n) {
    int res = 0;
    int ps[n], ns[n];

    stack<int> s;
    s.push(0);
    for (int i = 0; i < n; i++) {
        while (s.empty() == false && arr[s.top()] >= arr[i])
            s.pop();
        int pse = s.empty() ? -1 : s.top();
        ps[i] = pse;
        s.push(i);
    }

    while (s.empty() == false) {
        s.pop();
    }

    s.push(n - 1);
    for (int i = n - 1; i > 0; i--) {
        while (s.empty() == false && arr[s.top()] >= arr[i])
            s.pop();
        int nse = s.empty() ? n : s.top();
        ns[i] = nse;
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        curr += (i - ps[i] - 1) * arr[i];
        curr += (ns[i] - i - 1) * arr[i];
        res = max(res, curr);
    }
    return res;
}

// Effieient O(n)
int getMaxArea(int arr[], int n) {
    stack<int> s;
    int res = 0;
    int tp;
    int curr;

    // while pushing new item check of stack
    // -- if it larger than current item pop it and calculate area with it
    // -- else push current item
    for (int i = 0; i < n; i++) {
        while (s.empty() == false && arr[s.top()] >= arr[i]) {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }

    // at the end stach will have item with no greatest element only
    // privious smallest except last item on the stack
    // pop it and calculate area with it
    while (s.empty() == false) {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}

int main() {
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = 7;
    cout << "Maximum Area: " << getMaxArea(arr, n);
    return 0;
}
