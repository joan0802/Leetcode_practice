class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int maxl = -1, maxnum = -1;
        vector<int> ans;
        vector<int> dp(len, 1);
        vector<int> pre(len, -1);
        for(int i = 0; i < len; ++i) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if(dp[i] > maxl) {
                maxl = dp[i];
                maxnum = i;
            }
        }
        while(maxnum != -1) {
            ans.push_back(nums[maxnum]);
            maxnum = pre[maxnum];
        }
        return ans;
    }
};