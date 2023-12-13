class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx = -1, len = candies.size();
        for(auto i: candies) {
            if(i > mx) mx = i;
        }
        for(int i = 0; i < len; i++) {
            ans.push_back((candies[i] + extraCandies >= mx) ? true : false);
        }
        return ans;
        // candies + extracandies >= max
    }
};