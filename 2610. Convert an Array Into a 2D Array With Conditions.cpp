class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for(auto n: nums) {
            mp[n]++;
            cnt = max(cnt, mp[n]);
        }
        vector<vector<int>> ans(cnt);
        for(auto n: mp) {
            int same = n.second;
            for(int i = 0; i < same; i++) {
                ans[i].push_back(n.first);
            }
        }
        return ans;
    }
};