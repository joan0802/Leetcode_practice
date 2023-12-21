class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++) {
            int cnt = 0, tmp = i;
            while(tmp > 0) {
                if(tmp % 2 == 1)
                    cnt++;
                tmp /= 2;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};