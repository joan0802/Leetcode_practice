class Solution {
public:
    bool isPalindrome (string s, int start, int end){
        while(start <= end) {
            if(s[start] != s[end]) 
                return false;
            start++;
            end--;
        }
        return true;
    }
    void part(string& s, vector<string>& tmp, int cur, vector<vector<string>>& ans) {
        int len = s.size();
        if(cur == len) {
            ans.push_back(tmp);
            return;
        }
        for(int i = cur; i < len; ++i) {
            if(isPalindrome(s, cur, i)) {
                tmp.push_back(s.substr(cur, i-cur+1));
                part(s, tmp, i+1, ans);
                tmp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> ans;
        part(s, tmp, 0, ans);
        return ans;
    }
};