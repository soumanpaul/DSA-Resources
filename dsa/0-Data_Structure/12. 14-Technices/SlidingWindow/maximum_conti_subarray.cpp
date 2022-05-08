// Sliding window solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int curr = nums[0];
        for(int i=1; i< nums.size();i++){
            curr = max(curr+nums[i], nums[i]);
            result = max(result,curr);
        }
        return result;
    }


    // N^3 solution
    
};
