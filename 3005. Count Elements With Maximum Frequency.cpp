class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = -1;
        int ans = 0;
        unordered_map<int, int> f;
        for(auto &n: nums) {
            f[n]++;
            if(f[n] > mx)
                mx = f[n];
        }
        for(auto &it: f) {
            if(it.second == mx)
                ans += mx;
        }
        return ans;
    }
};