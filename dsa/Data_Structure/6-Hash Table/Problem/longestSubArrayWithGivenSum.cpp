#include <bits/stdc++.h>
using namespace std;

int longestSubArrayWithSumX(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    int length = 0;

    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum ==  sum )
        {
            
        }
        s.insert(pre_sum);
    }
    return length;
}

int main()
{
    int arr[] = {3, 8, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 14;

    cout << longestSubArrayWithSumX(arr, n, X);
    return 0;
}