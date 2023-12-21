class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int len = potions.size();
        for(auto n: spells) {
            int left = 0, right = potions.size()-1, cur;
            while(left <= right) {
                cur = left + (right-left)/2;
                long long val = (long)potions[cur] * n;
                if(val >= success) { // too big
                    right = cur - 1;
                }
                else if(val < success) { // too small
                    left = cur + 1;
                }
            }
            // left 為剛好大於等於 success 的數字
            ans.push_back(len - left);
        }
        return ans;
    }
};