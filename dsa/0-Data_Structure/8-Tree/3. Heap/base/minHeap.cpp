#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }
    ~MinHeap() { delete[] harr; }

    void MinHeapify(int); // Implemented in user editor
    void insertKey(int k);
    void deleteKey(int i);
    int extractMin();

    void decreaseKey(int i, int new_val);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
};

// // To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

//// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void heapify(int arr[], int n, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0) {
        // For Max-Heap
        // If current node is greater than its parent Swap both of them and call heapify again for the parent
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapify(arr, n, parent);
        }
    }
}

// Function to insert a value in Heap.
void MinHeap::insertKey(int k) {
    if (heap_size == capacity)
        return;
    harr[heap_size] = k;
    heap_size++;
    int i = heap_size - 1;
    while (i != heap_size && harr[i] < harr[parent(i)]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to delete a key at ith index.
void MinHeap::deleteKey(int i) {
    if (i >= heap_size || heap_size <= 0)
        return;
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to extract minimum value in heap and then to store
// next minimum value at first index.
// Process of Root Deletion (Or Extract Min in Min Heap):
int MinHeap::extractMin() {
    if (heap_size <= 0)
        return -1;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    swap(harr[0], harr[heap_size - 1]);
    heap_size--;
    MinHeapify(0);
    return harr[heap_size];
}

// Driver code
int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a;
        cin >> a;
        MinHeap h(a);
        for (ll i = 0; i < a; i++) {
            int c;
            int n;
            cin >> c;
            if (c == 1) {
                cin >> n;
                h.insertKey(n);
            }
            if (c == 2) {
                cin >> n;
                h.deleteKey(n);
            }
            if (c == 3) {
                cout << h.extractMin() << " ";
            }
        }
        cout << endl;
        h.harr = NULL;
    }
    return 0;
}