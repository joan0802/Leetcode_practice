class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>> q;
        vector<pair<int, int>> adj[n];
        vector<int> dist(n, 1e9);
        int ans = -1;
        for(auto f: flights) {
            adj[f[0]].push_back({f[1], f[2]}); // to, price
        }
        q.push({0, {src, src}});
        dist[src] = 0;
        do {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto t = q.front();
                q.pop();
                int from = t.second.first;
                int to = t.second.second;
                int p = t.first;
                for(auto it: adj[to]) {
                    if(dist[it.first] > p + it.second) {
                        q.push({p + it.second, {to, it.first}});
                        dist[it.first] = p + it.second;
                    }
                }
            }
        } while(!q.empty() && k--);
        if(dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};