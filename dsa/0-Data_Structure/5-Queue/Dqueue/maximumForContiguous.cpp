//  Sliding Window Maximum
// Description - Given an array and an integer k, find the maximum for each and
// every contiguous subarray of size k.
/*
We create a Deque, Qi of capacity k, that stores only useful elements of current window
of k elements. An element is useful if it is in current window and is greater than all
 other elements on left side of it in current window. We process all array elements one by
 one and maintain Qi to contain useful elements of current window and these useful elements
  are maintained in sorted order. The element at front of the Qi is the largest and element
at rear of Qi is the smallest of current window.
*/

#include <bits/stdc++.h>
using namespace std;

void printKMax(int const arr[], int n, int k) {

    deque<int> Qi(k);

    /* Process first k (or first window) elements of array */
    // if deque item is smaller than the current item remove dequeue item
    // dqueue will be sorted

    for (int i = 0; i < k; ++i) {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back(); // Remove from rear
        Qi.push_back(i);
    }

    for (int i = k; i < n; ++i) {

        // print front with is max of previous window
        cout << Qi.front();

        // check font of qi is in range of current window else delete from front
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front(); // Remove from front of queue

        // if deque item is smaller than the current item remove dequeue item
        // dqueue will be sorted
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }
}

int main() {
    int arr[] = {20, 40, 30, 10, 60}, n = 5;
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}