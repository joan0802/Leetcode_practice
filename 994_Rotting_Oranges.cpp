struct orange {
    int i;
    int j;
    int time;
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int map[11][11];
        int m = grid.size();
        int n = grid[0].size();
        int total_time = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        queue<orange> rot;
        for(int i = 0; i < m; i++) {
            int index = 0;
            for(auto j: grid[i]) {
                if(j == 2) {
                    orange o;
                    o.i = i, o.j = index, o.time = 0;
                    rot.push(o);
                }
                map[i][index++] = j;
            }
        }
        while(!rot.empty()) {
            orange st = rot.front();
            rot.pop();
            for(int i = 0; i < 4; i++) {
                int ni = st.i + di[i];
                int nj = st.j + dj[i];
                if(ni < m && nj < n && ni >= 0 && nj >= 0 && map[ni][nj] == 1) {
                    map[ni][nj] = 2;
                    orange o;
                    o.i = ni, o.j = nj, o.time = st.time + 1;
                    rot.push(o);
                }
            }
            total_time = st.time;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == 1)
                    return -1;
            }
        }
        return total_time;
    }
};