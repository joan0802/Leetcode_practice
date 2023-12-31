class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int len = s.size();
        if(len == 0)
            return 0;
        unordered_map<char, int> mp;
        int l = 0, r = 1;
        mp[s[l]]++;
        while(r < len) {
            if(mp.count(s[r]) == 0 || mp[s[r]] == 0) {
                mp[s[r]] = 1;
                r++;
                ans = max(ans, r-l);
            }
            else {
                while(mp[s[r]] == 1) {
                    mp[s[l]] = 0;
                    l++;
                }
            }
        }
        return ans;
    }
};