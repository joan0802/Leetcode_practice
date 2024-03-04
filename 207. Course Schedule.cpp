class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);
        queue<int> q;
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        for(int i = 0; i < in.size(); ++i) {
            if(in[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int top = q.front();
                q.pop();
                for(auto it: adj[top]) {
                    in[it]--;
                    if(in[it] == 0) {
                        q.push(it);
                    }
                }
            }
        }
        for(auto it: in) {
            if(it != 0)
                return false;
        }
        return true;
    }
};