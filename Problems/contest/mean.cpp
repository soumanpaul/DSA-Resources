#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;



// class Solution {
// public:
//     double trimMean(vector<int>& arr) {
//         int length = arr.size();
//         sort(arr.begin(), arr.end()); 
//         int item = (length *5)/100;
//         int start = item +1, end = length - item, number=length - item*2;
//         double total = 0;
//         for (int i = start; i <= end ; i++)
//             total+= arr[i];
        
//         return total/number;
//     }
// };

double trimMean(vector<int>& arr) {
        int length = arr.size();
        sort(arr.begin(), arr.end()); 
        int item = (length *5)/100;
        int start = item , end = length - item, number=length - item*2;
        double total = 0;
        cout << " Start " << start << " end " << end << " number " << number << endl;
        for (int i = start; i < end ; i++){
            total+= arr[i];
            
            }
        
        return total/number;
    }

int main() {

    vector<int> arr = {6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4};

    cout << "Mean....." << trimMean(arr);
    return 0;
}