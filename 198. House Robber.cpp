class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int len = nums.size();
        for(int i = 2; i < len; i++) {
            for(int j = i-2; j >= 0; j--) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        return max(dp[len-1], dp[len-2]);
    }
};

// nums: 4 1 3 10
// dp  : 4 1 7 14

// nums: 4 1 3 2
// dp  : 4 1 7 6

// 0 or 1 must selected
// dp =  (0 ~ index - 2 maximum) + nums[index] O(n^2)