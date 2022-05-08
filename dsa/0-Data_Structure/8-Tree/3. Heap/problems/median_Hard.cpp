// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Function to insert heap.
    void insertHeap(int &x) {

        if (maxHeap.size() > minHeap.size()) {
            if (maxHeap.top() > x) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
        } else if (maxHeap.size() < minHeap.size()) {
            if (x > maxHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            } else {
                maxHeap.push(x);
            }
        } else {
            if (x < maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
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
            // if(i==1) ob.maxHeap.push();
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} // } Driver Code Ends