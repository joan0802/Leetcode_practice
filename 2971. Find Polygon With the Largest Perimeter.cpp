class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = -1;
        long long cur = nums[0] + nums[1];
        for(int i = 2; i < nums.size(); ++i) {
            if(cur > nums[i]) {
                cur += nums[i];
                ans = cur;
            }
            else
                cur += nums[i];
        }
        return ans;
    }
};