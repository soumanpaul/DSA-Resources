
// C++ code to find the union of
// two unsorted arrays
#include <bits/stdc++.h>
using namespace std;

// Created an unordered_set
unordered_set<int> s;

// Function to print the union of
// two unsorted arrays
void printUnion(int arr1[], int arr2[],
                int m, int n) {
    // Inserting arr1 elements
    // into an unordered_set
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
        s.insert(arr1[i]);
    }

    // searching and printing the
    // elements of arr2[] that is
    // absent in arr1[]
    for (int i = 0; i < n; i++) {
        if (s.find(arr2[i]) == s.end()) {
            cout << arr2[i] << " ";
        }
    }
}

// Driving Method
int main() {
    // First array arr1[]
    int arr1[] = {7, 6, 13, 10};
    int m = 4;

    // Second array arr2[]
    int arr2[] = {10, 9, 4, 5, 7, 20};
    int n = 6;

    // Calling the Union method
    printUnion(arr1, arr2, m, n);
    return 0;
}
