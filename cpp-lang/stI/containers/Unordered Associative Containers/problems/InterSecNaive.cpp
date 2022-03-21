#include <bits/stdc++.h>
using namespace std;

void printIntersect(int arr1[], int arr2[], int m, int n) {
    // Sorting the second array
    sort(arr2, arr2 + n);

    // Beginning the search operation
    for (i = 0; i < m; i++) {
        if (search(arr1[i], arr2[], n)) {
            cout << arr1[i];
        }
    }
}

// Binary search for arr2[i] in arr1[]
bool search(int x, int arr1[], int m) {
    for (i = 0; i < m; i++) {
        if (arr[i] == x)
            return true;
        return false;
    }
}

// ////////////////////////////////////////// loop

void printIntersect(int arr1[], int arr2[], int m, int n) {
    // Beginning the search operation
    for (i = 0; i < m; i++) {
        if (search(arr1[i], arr2[], n)) {
            cout << arr1[i];
        }
    }
}

// Linear search for arr2[i] in arr1[]
bool search(int x, int arr1[], int m) {
    for (i = 0; i < m; i++) {
        if (arr[i] == x)
            return true;
        return false;
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
