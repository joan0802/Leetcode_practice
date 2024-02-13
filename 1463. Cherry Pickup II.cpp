class Solution {
public:
    int dj[3] = {-1, 0, 1};
    int dp[105][75][75];
    int ans = -INT_MAX;
    int n, m;
    void DFS(vector<vector<int>>& grid, int p1, int p2, int r, int total) {
        if(dp[r][p1][p2] == -1)
            dp[r][p1][p2] = total;
        if(r == n-1) {
            ans = max(ans, total);
            return;
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int np1 = p1 + dj[i];
                int np2 = p2 + dj[j];
                if(np1 >= 0 && np1 < m && np2 >= 0 && np2 < m) {
                    if(np1 == np2 && dp[r][np1][np2] == -1)
                        DFS(grid, np1, np2, r+1, total + grid[r+1][np1]);
                    else if(dp[r][np1][np2] == -1)
                        DFS(grid, np1, np2, r+1, total + grid[r+1][np1] + grid[r+1][np2]);
                }
            }
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, 0, sizeof(dp));
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < m; j++) { // robotA
                for(int k = j + 1; k < m; k++) { // robot B
                    for(int a = 0; a < 3; a++) { // robotA step
                        for(int b = 0; b < 3; b++) { // robotB step
                            if(j+dj[a] >= 0 && j+dj[a] < m && k+dj[b] >= 0 && k+dj[b] < m)
                                dp[i][j][k] = max(dp[i][j][k], dp[i+1][j+dj[a]][k+dj[b]]);
                        }
                    }
                    dp[i][j][k] += grid[i][j] + grid[i][k];
                }
            }
        }
        return dp[0][0][m-1];
    }
};