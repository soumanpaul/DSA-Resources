
// C++ program to print the
// duplicate elements of array
#include <bits/stdc++.h>
using namespace std;

// Function to print the duplicate
void printDuplicate(int arr[], int n) {
    // Creating an unordered_set
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        // If repeititions are found
        if (st.find(arr[i]) != st.end())
            cout << arr[i] << " ";

        else
            st.insert(arr[i]);
    }
}

// Driver method
int main() {
    int arr[] = {7, 2, 5, 9, 4, 2, 7, 10};
    int n = 8;
    printDuplicate(arr, n);
    return 0;
}
