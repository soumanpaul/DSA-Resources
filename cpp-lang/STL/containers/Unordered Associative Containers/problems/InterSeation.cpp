
// C++ code to find the intersection of
// two unsorted arrays
#include <bits/stdc++.h>
using namespace std;

// Created an unordered_set
unordered_set<int> s;

// Function to print the intersection
// of two unsorted arrays
void printIntersect(int arr1[], int arr2[],
                    int m, int n) {
    // Inserting arr2 elements
    // into an unordered_set
    for (int i = 0; i < n; i++) {
        s.insert(arr2[i]);
    }

    // Searching for arr1[] in arr2[]
    // Printing the common elements
    for (int i = 0; i < m; i++) {
        if (s.find(arr1[i]) != s.end()) {
            cout << arr1[i] << " ";
        }
    }
}

// Driving Method
int main() {
    // First array arr1[]
    int arr1[] = {7, 2, 9, 15, 10};
    int m = 5;

    // Second array arr2[]
    int arr2[] = {5, 10, 7, 3, 2, 20, 9};
    int n = 7;

    // Calling the Intersect method
    printIntersect(arr1, arr2, m, n);
    return 0;
}
