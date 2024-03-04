class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> know(n, false);
        vector<pair<int, int>> adj[n];
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto m: meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if(know[top.second] == true)
                continue;
            know[top.second] = true;
            for(auto n: adj[top.second]) {
                if(!know[n.first] && n.second >= top.first) {
                    pq.push({n.second, n.first});
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(know[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};