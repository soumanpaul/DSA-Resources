#include <cmath>
#include <iostream>
using namespace std;

void reverse(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
void rvereseArray(int arr[], int start, int end) {
    if (start >= end)
        return;

    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
}

int main() {

    int arr[] = {10, 5, 7, 30}, n = 4;
    reverse(arr, n);
    cout << "After Reverse" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}