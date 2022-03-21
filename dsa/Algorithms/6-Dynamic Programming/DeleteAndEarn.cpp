#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int t[21001];
    int recurrence(vector<int> &arr, int i) {
        if (i >= arr.size())
            return 0;
        if (t[i] != -1)
            return t[i];
        int current_value = arr[i];
        int current__sum = arr[i];
        int index = i + 1;
        while (index < arr.size() && arr[index] == current_value) {
            current__sum += arr[i];
            index++;
        }
        while (index < arr.size() && arr[index] == current_value + 1)
            index++;

        return t[i] = max(current__sum + recurrence(arr, index), recurrence(arr, i + 1));
    }
    int deleteAndEarn(vector<int> &arr) {
        int n = arr.size();
        memset(t, -1, sizeof(t));
        sort(arr.begin(), arr.end());
        return recurrence(arr, 0);
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int> &arr) {
        }
};