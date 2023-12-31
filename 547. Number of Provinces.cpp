// Sol1 -> time complexity: O(n^2)
// Disjoint Set(may be skewed)
class Solution {
public:
    int findParent(int x) {
        if(parent[x] != x)
            return findParent(parent[x]);
        return x;
    }
    void unionSet(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        parent[py] = px;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int node = 0, cnt = 0;
        int n = isConnected.size();
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(auto it: isConnected) {
            for(int i = node+1; i < n; i++) {
                if(it[i] == 1)
                    unionSet(node, i);
            }
            node++;
        }
        for(int i = 0; i < n; i++) {
            if(parent[i] == i)
                cnt++;
            cout << parent[i] << " ";
        }
        return cnt;
    }
private:
    int parent[200];
};

// Sol2 -> time complexity: O(n^2)
// DFS approach
class Solution {
public:
    int vis[200];
    int n;
    void DFS(int x, vector<vector<int>>& isConnected, int cnt) {
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0 && isConnected[x][i] == 1) {
                vis[i] = 1;
                DFS(i, isConnected, cnt);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
            vis[i] = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                DFS(i, isConnected, cnt);
                cnt++;
            }
        }
        return cnt;
    }
};