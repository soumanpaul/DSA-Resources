class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp1, mp2;
        for(int i=0;i< nums1.size();i++){
           mp1[nums1[i]]++;
        }
        for(int i=0;i< nums2.size();i++){
           mp2[nums2[i]]++;
        }
        for(auto x : mp1){
            if(mp2.find(x.first) !=mp2.end()){
                auto y = mp2.find(x.first);
                int item = min(x.second, y->second);
                for(int i=0;i<item;i++){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};