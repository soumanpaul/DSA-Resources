// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    double med;
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;

public:
    // Function to insert heap.
    void insertHeap(int &x) {
        // if(maxHeap.empty()){
        //     maxHeap.push(x);
        //     return;
        // }
        if (maxHeap.size() > minHeap.size()) {
            if (x < med) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
            med = maxHeap.top() + minHeap.top() / 2.0;
        } else if (maxHeap.size() < minHeap.size()) {
            if (x > med) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            } else {
                maxHeap.push(x);
            }
            med = maxHeap.top() + minHeap.top() / 2.0;
        } else {
            if (x < med) {
                maxHeap.push(x);
                med = (double)maxHeap.top();
            } else {
                minHeap.push(x);
                med = (double)x;
            }
        }
    }

    // Function to balance heaps.
    void balanceHeaps() {
    }

    // Function to return Median.
    double getMedian() {
        // return med;
        if (maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        } else {
            return (double)maxHeap.top();
        }
    }
};

// { Driver Code Starts.

int main() {
    int n, x;
    int t;
    cin >> t;
    while (t--) {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} // } Driver Code Ends