class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        vector<int> freq;
        int ans = 0;
        for(auto n: arr)
            m[n]++;
        for(auto &it: m)
            freq.push_back(it.second);
        ans = freq.size();
        sort(freq.begin(), freq.end());
        for(auto n: freq) {
            if(k <= 0)
                break;
            if(n <= k) {
                k -= n;
                ans--;
            }
        }
        return ans;
    }
};