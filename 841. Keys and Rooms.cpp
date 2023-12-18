class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool vis[rooms.size()];
        int cnt = 0;
        memset(vis, false, rooms.size());
        queue<int> key;

        key.push(0);
        vis[0] = true;
        cnt++;
        while(!key.empty()) {
            int top = key.front();
            key.pop();
            for(auto i: rooms[top]) {
                if(vis[i] == false) {
                    key.push(i);
                    vis[i] = true;
                    cnt++;
                }
            }
        }
        return (cnt == rooms.size()) ? true : false;
    }
};