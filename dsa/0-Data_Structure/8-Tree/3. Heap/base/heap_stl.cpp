/*
For implementing Max Heap:
    priority_queue< type_of_data > name_of_heap;
For implementing Min Heap:
    priority_queue< type, vector<type>, greater<type> > name_of_heap;

Methods of priority queue:

priority_queue::empty(): The empty() function returns whether the queue is empty.
priority_queue::size(): The size() function returns the size of the queue.
priority_queue::top(): This function returns a reference to the top most element of the queue.
priority_queue::push(): The push(g) function adds the element ‘g’ at the end of the queue.
priority_queue::pop(): The pop() function deletes the first element of the queue.
priority_queue::swap(): This function is used to swap the contents of one priority queue with another priority queue of same type and size.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // DECLARING MAX HEAP
    priority_queue<int> max_heap;

    // Add elements to the Max Heap
    // in any order
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    max_heap.push(5);
    max_heap.push(1);

    // Print element at top of the heap
    // every time and remove it until the
    // heap is not empty
    cout << "Element at top of Max Heap at every step:\n";
    while (!max_heap.empty()) {
        // Print Top Element
        cout << max_heap.top() << " ";
        // Remove Top Element
        max_heap.pop();
    }

    // DECLARING MIN HEAP
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Add elements to the Min Heap
    // in any order
    min_heap.push(10);
    min_heap.push(30);
    min_heap.push(20);
    min_heap.push(5);
    min_heap.push(1);

    // Print element at top of the heap
    // every time and remove it until the
    // heap is not empty
    cout << "\n\nElement at top of Min Heap at every step:\n";
    while (!min_heap.empty()) {
        // Print Top Element
        cout << min_heap.top() << " ";
        // Remove Top Element
        min_heap.pop();
    }

    return 0;
}
