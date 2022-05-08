
// Program to find the frequency
// of each element of an array
#include <bits/stdc++.h>
using namespace std;

// Method to find the frequency
// of each element
void printFrequencies(int arr[], int n) {
    // Creating an unordered_map
    unordered_map<int, int> mp;

    // Counting the frequency
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    // Printing the frequency of
    // each element
    for (auto x : mp)
        cout
            << x.first << "-" << x.second << endl;
}

// Drivers method
int main() {
    int arr[] = {10, 20, 20, 10, 10, 5, 15};
    int n = 8;

    // Displaying the array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Calling the function to find
    // the frequency
    printFrequencies(arr, 7);
    return 0;
}
