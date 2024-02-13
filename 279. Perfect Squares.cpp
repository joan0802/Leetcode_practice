class Solution {
public:
    int numSquares(int n) {
        int dp[10005];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1] + 1;
            for(int j = 1; j <= sqrt(i); j++) {
                dp[i] = min(dp[ i-j*j ]+1, dp[i]);
            }
        }
        return dp[n];
    }
};