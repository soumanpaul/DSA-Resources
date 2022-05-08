#include <bits/stdc++.h>
using namespace std;

void MinHeap(int a[], int size) {
    int heap_size = size
        harr = a // store address of array
        int i = (heap_size - 1) / 2 while (i >= 0) {
        MinHeapify(i)
            i--
    }
}

int extractMin() {
    if (heap_size == 0)
        return INT_MAX;
    // Store the minimum vakue.
    int root = harr[0];
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1) {
        harr[0] = harr[heap_size - 1] MinHeapify(0)
    }
    heap_size--;
    return root
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeapify(int i) {
    int l = left(i) int r = right(i) int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l if (r < heap_size && harr[r] < harr[smallest])
            smallest = r if (smallest != i) {
            swap(&harr[i], &harr[smallest])
                MinHeapify(smallest)
        }
}
// Returns Minimum Element
int getMin() {
    return harr[0]
}
// Function to return k'th smallest element in a given array
int kthSmallest(arr[], n, k) {
    // Build a heap of n elements: O(n) time
    MinHeap(arr, n)

        // Do extract min (k-1) times
        for (int i = 0; i < k - 1; i++)
            extractMin() return getMin()
}