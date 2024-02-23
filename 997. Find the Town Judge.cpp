class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> betst(n+1, 0);
        vector<int> tst(n+1, 0);
        for(auto t: trust) {
            betst[t[1]]++;
            tst[t[0]] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            if(betst[i] == n-1 && tst[i] == 0)
                return i;
        }
        return -1;
    }
};