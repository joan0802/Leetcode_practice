class Solution {
public:
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, -1, 0, 1};
    bool DFS(vector<vector<char>>& board, string& word, pair<int, int> st, int cnt, int vis[6][6]) {
        // cout << cnt << endl;
        if(cnt == word.size()) {
            return true;
        }
        for(int i = 0; i < 4; ++i) {
            int nx = st.first + di[i];
            int ny = st.second + dj[i];
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()) {
                if(vis[nx][ny] == 0 && board[nx][ny] == word[cnt]) {
                    vis[nx][ny] = 1;
                    if(DFS(board, word, {nx, ny}, cnt+1, vis))
                        return true;
                    vis[nx][ny] = 0;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int vis[6][6];
        vector<pair<int, int>> w;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == word[0]) {
                    w.push_back({i, j});
                }
            }
        }
        for(auto st: w) {
            vis[st.first][st.second] = 1;
            if(DFS(board, word, st, 1, vis) == true)
                return true;
            vis[st.first][st.second] = 0;
        }
        return false;
    }
};