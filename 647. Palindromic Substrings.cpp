class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.size();
        int dp[1005][1005];
        for(int i = len-1; i >= 0; --i) {
            for(int j = i; j < len; ++j) {
                if (i == j) {
                    dp[i][j] = true;
                } 
                else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                } 
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                if(dp[i][j])
                    ans++;
            }
        }
        return ans;
    }
};