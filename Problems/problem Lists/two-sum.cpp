class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {     
        unordered_map<int, int> se;
        for(int i=0; i<nums.size();i++){
            auto itr = se.find((target-nums[i]));
            if( itr!= se.end()){
                return {itr->second,i};
            }
            se.insert({nums[i], i});
        }
        return {};
    }
     int twoSum(int nums[], int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return  { i, j };
                }
            }
        }
        // In case there is no solution, we'll just return null
        return null;
    }
};