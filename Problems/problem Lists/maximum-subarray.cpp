// Sliding window solution
class Solution {
public:
    // Solution 1: Naive Approach[ N^3 solution]
    int maxSubArray(vector<int>& nums, vector<int>& subarray){
        int max_sum = 0;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0; i<n; i++){
            for(j=i; j<n; j++){
                int sum=0;
                for(int k=i; k<=j; k++){
                    sum+=nums[k];
                }
                if(sum>max_sum){
                    max_sum = sum;
                    subarray.clear();
                    subarray.push_back(i);
                    subarray.push_back(j);
                }
            }
        }    
        return max_sum;
    }

    //  N^2 solution
    int maxSubArray(vector < int > & nums, vector < int > & subarray) {
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int curr_sum = 0;
                for (int j = i; j < nums.size(); j++) {
                    curr_sum += nums[j];
                    if (curr_sum > max_sum) {
                        subarray.clear();
                        max_sum = curr_sum;
                        subarray.push_back(i);
                        subarray.push_back(j);
                    }
                }
        }
        return max_sum;
    }


    // Kadane's Algorithm  N^1 solution
   int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>subarray;
        int result = nums[0];
        int curr = nums[0];
        int s = 0;
        for(int i=1; i< nums.size();i++){
            curr = max(curr+nums[i], nums[i]);
            if(curr > result){
                subarray.clear();
                subarray.push_back(s);
                subarray.push_back(i);
            }
            result = max(result,curr);
            if(curr < 0){
                curr = 0;
                s = i+1;
            }
        }
        return result;
    }

    
};
