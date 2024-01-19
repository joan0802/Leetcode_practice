class Solution {
public:
    int di[3] = {1, 1, 1};
    int dj[3] = {-1, 0, 1};
    int dp[105][105];
    int bound = 0;
    int ans = INT_MAX;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        bound = matrix[0].size();
        for(int i = 0; i < bound; ++i) {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < bound; ++i) {
            for(int j = 0; j < bound; ++j) {
                if(j-1 < 0)
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                else if(j+1 >= bound)
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];
                else
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]}) + matrix[i][j];
            }
        }
        for(int i = 0; i < bound; ++i) {
            ans = min(ans, dp[bound-1][i]);
        }
        return ans;
    }
};