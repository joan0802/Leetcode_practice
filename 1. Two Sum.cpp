class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int len = nums.size();
        vector<int> ans;
        for(int i = 0; i < len; i++) {
            if(mp.size()) {
                if(mp.count(nums[i])) {
                    return {mp[nums[i]], i};
                }
            }
            mp[target-nums[i]] = i;
        }
        return ans;
    }
};