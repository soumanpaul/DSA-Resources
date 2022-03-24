#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

int ZeroSumSubarray(int arr[], int n)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    us.insert(0);
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (us.find(prefix_sum) != us.end())
            return 1;
        us.insert(prefix_sum);
    }
    return 0;
}

bool isSum(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++)
    {   
        if(pre_sum==sum)
            return true;
        pre_sum += arr[i];
        if(s.find(pre_sum-sum) != s.end())
          return true;
        s.insert(pre_sum);
    }
    return false;
}

int main()
{
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << ZeroSumSubarray(arr, n) << endl;
    ;

    int arr1[] = {15,2, 8, 10, -5, -8, 6};
    int n1 = sizeof(arr) / sizeof(arr[0]);

    cout << isSum(arr1, n1, 3);
}