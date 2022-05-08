#include <bits/stdc++.h>
using namespace std;

// function to calculate median of stream
double printMedian(double arr[], int n) {

    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

    double med = arr[0];
    s.push(arr[0]);

    // reading elements of stream one by one
    for (int i = 1; i < n; i++) {
        double x = arr[i];
        // case1(left side heap has more elements)
        if (s.size() > g.size()) {
            if (x < med) {
                g.push(s.top());
                s.pop();
                s.push(x);
            } else
                g.push(x);

            med = (s.top() + g.top()) / 2.0;
        }

        // case2(both heaps are balanced)
        else if (s.size() == g.size()) {
            if (x < med) {
                s.push(x);
                med = (double)s.top();
            } else {
                g.push(x);
                med = (double)g.top();
            }
        }

        // case3(right side heap has more elements)
        else {
            if (x > med) {
                s.push(g.top());
                g.pop();
                g.push(x);
            } else
                s.push(x);

            med = (s.top() + g.top()) / 2.0;
        }
    }
    return med;
}