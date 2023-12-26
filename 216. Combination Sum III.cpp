class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(int cnt, int total, int n, int k, vector<int> tmp) {
        if(total == n && cnt == k) {
            ans.push_back(tmp);
            return;
        }
        if(total > n || cnt > k)
            return;
        int pre = (tmp.size()) ? tmp.back() : 0;
        for(int i = pre+1; i <= 9; i++) {
            tmp.push_back(i);
            backTrack(cnt+1, total+i, n, k, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        backTrack(0, 0, n, k, tmp);
        return ans;
    }
};