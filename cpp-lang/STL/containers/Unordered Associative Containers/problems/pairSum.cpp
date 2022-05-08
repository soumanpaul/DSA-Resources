
// C++ program to check for the pair's sum
// matching to given sum

#include <bits/stdc++.h>
using namespace std;

// Function to check for the pair
bool checkForPair(int arr[], int n, int sum) {

    // Creating an unordered_set
    unordered_set<int> set;

    // Loop traversing the array
    for (int i = 0; i < n; i++) {
        // Finding the complement
        int comp = sum - arr[i];

        // Checking for the complement in
        // the set
        if (set.find(comp) != set.end())
            return true;

        // Inserting the i-th
        // element into the set
        set.insert(arr[i]);
    }

    // If no such pair is found
    return false;
}

// Driving code
int main() {
    // Base array
    int arr[] = {5, 9, 8, 13, 2, 4};

    // Size and value and sum
    int n = 6, sum = 7;

    // Calling the function to check
    // for the pair
    cout << checkForPair(arr, n, sum);
    return 0;
}
