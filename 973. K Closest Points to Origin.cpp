class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k);
        vector<pair<int, int>> tmp;
        int cnt = 0;
        for(auto p: points) {
            tmp.push_back({p[0]*p[0]+p[1]*p[1], cnt});
            ++cnt;
        }
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < k; i++) {
            ans[i] = points[tmp[i].second];
        }
        return ans;
    }
};