class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        string ans = "";
        int l = 0, r = 0;
        while(r <= s.size()) {
            if(r == s.size() || s[r] == ' ') {
                if(l != r) {
                    tmp.push_back(s.substr(l, r-l)); 
                }ㄩㄥ
                r++;
                l = r;
            }
            else 
                r++;
        }
        int len = tmp.size();
        for(int i = len-1; i >= 0; i--) {
            ans += tmp[i];
            if(i != 0)
                ans += " ";
        }
        return ans;
    }
};