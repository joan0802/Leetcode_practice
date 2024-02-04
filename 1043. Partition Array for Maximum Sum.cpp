class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int dp[505] = {0};
        for(int i = 1; i <= arr.size(); ++i) {
            int mx = arr[i-1];
            for(int j = 1; j <= k; ++j) {
                if(i-j < 0) break;
                mx = max(arr[i-j], mx);
                dp[i] = max(dp[i-j] + mx*(j), dp[i]);
            }
        }
        return dp[arr.size()];
    }
};