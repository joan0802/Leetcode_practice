class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int tmp = target;
        int len = 0, left = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] > target)
                return 1;
            tmp -= nums[i];
            len++;
            if(tmp <= 0) {
                while(tmp <= 0) {
                    ans = min(ans, len);
                    tmp += nums[left];
                    len--;
                    left++;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};