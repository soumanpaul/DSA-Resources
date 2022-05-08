
int getLargest(int arr[], int n) {
    int res = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[res])
            res = i;
    return res;
}

int secondLargest(int arr[], int n) {
    int largest = getLargest(arr, n);
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[largest])
            if (res == -1)
                res = i;
            else if (arr[i] > arr[res])
                res = i;
    }
    return res;
}

// T = O(n)
int secondlargest(int a[], int n) {
    int largest = 0;
    int res = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[largest]) {
            res = largest;
            largest = i;
        } else if (a[i] != a[largest]) {
            if (res == -1 || a[i] > a[res])
                res = i;
        }
    }
    return res;
}