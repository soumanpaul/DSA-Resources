// Binary search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int position;
        position = findPosition(nums, 0, nums.size()-1,target);
        return position;
    }
    int findPosition(vector<int>& nums, int low, int high, int target){
        if(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid] < target){
                if(mid== nums.size()-1)
                    return mid+1;
                if(nums[mid+1] >= target)
                    return mid+1;
                return findPosition(nums, mid+1, high, target);
            }
            else if(nums[mid] > target){
                if(mid==0)
                    return 0;
                if(nums[mid-1] < target)
                    return mid;
                else if(nums[mid-1] == target) return mid-1;
                return findPosition(nums, low, mid, target);
            }
            else return mid+1;    
        }
        return low;
    }
};