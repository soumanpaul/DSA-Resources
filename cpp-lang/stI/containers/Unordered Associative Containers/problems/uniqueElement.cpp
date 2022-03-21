
// C++ program to print the
// distinct elements of an array
#include <bits/stdc++.h>
using namespace std;

// Function to print unique elements
void printUniqueElememt(int arr[], int n) {
    // Creating an unordered_set
    unordered_set<int> unique_set;

    // Inserting elements into set
    for (int i = 0; i < n; i++) {
        unique_set.insert(arr[i]);
    }

    // Displaying the set
    for (
        auto it = unique_set.begin();
        it != unique_set.end(); it++) {
        cout << *it << " ";
    }
}

int main() {
    int arr[] = {7, 2, 9, 4, 3, 2, 10, 4};
    int n = 7;
    printUniqueElememt(arr, n);
    return 0;
}
