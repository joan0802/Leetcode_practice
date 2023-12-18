class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int st_i = entrance[0], st_j = entrance[1];
        int iBound = maze.size();
        int jBound = maze[0].size();
        int ans = 0;
        int di[4] = {0, 0, -1, 1};
        int dj[4] = {1, -1, 0, 0};
        int vis[105][105];
        memset(vis, 0, sizeof(vis));
        queue< pair<int, int> > path;
        path.push(make_pair(st_i, st_j));
        vis[st_i][st_j] = 1;
        while(!path.empty()) {
            int size = path.size();
            for(int k = 0; k < size; ++k) {
                pair<int, int> top = path.front();
                path.pop();
                // cout << "top = " << top.first << " " << top.second << endl;
                if(top.first == 0 || top.second == 0 || top.first == iBound-1 || top.second == jBound-1) {
                    if(top.first != st_i || top.second != st_j) {
                        return ans;
                        // cout << "return ans \n";
                    }
                }
                for(int i = 0; i < 4; ++i) { // four directions
                    if(top.first + di[i] < 0 || top.first + di[i] >= iBound)
                        continue;
                    if(top.second + dj[i] < 0 || top.second + dj[i] >= jBound)
                        continue;
                    if(maze[ top.first + di[i] ][ top.second + dj[i] ] == '.') {
                        if(vis[top.first + di[i]][top.second + dj[i]] == 0) {
                            vis[top.first + di[i]][top.second + dj[i]] = 1;
                            path.push( make_pair( top.first + di[i], top.second + dj[i]) );
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
