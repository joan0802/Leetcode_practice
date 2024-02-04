class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        unordered_map<char, int> t_char;
        unordered_map<char, int> cur;
        string ans = "";
        int l = 0, required = 0, cnt = 0;
        int minLen = INT_MAX, minStart = -1;
        for(auto c: t) {
            t_char[c]++;
        }
        required = t_char.size();
        for(int i = 0; i < s.size(); i++) {
            if(t_char.count(s[i])) {
                cur[s[i]]++;
                if(cur[s[i]] == t_char[s[i]])
                    cnt++;
            }
            if(cnt == required) {
                while(cnt == required && l <= i) {
                    if(t_char.count(s[l])) {
                        if(i-l+1 < minLen) {
                            minLen = i-l+1;
                            minStart = l;
                        }
                        cur[s[l]]--;
                        if(cur[s[l]] < t_char[s[l]])
                            cnt--;
                    }
                    l++;
                }
            }
        }
        if(minLen == INT_MAX)
            return "";
        return s.substr(minStart, minLen);
    }
};