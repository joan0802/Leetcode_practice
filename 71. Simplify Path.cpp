class Solution {
public:
    string simplifyPath(string path) {
        // stack<char> st;
        string ans = "", tmp = "";
        int len = path.size();
        for(int i = 0; i < len; ++i) {
            if(path[i] == '/')
                continue;
            while(i < len && path[i] != '/') {
                tmp += path[i++];
            }
            if(tmp == ".")
                tmp = "";
            else if(tmp == "..") {
                while(ans.size() && ans[ans.size()-1] != '/') {
                    ans.pop_back();
                }
                if(ans.size())
                    ans.pop_back();
            }
            else {
                ans += '/';
                ans += tmp;
            }
            tmp = "";
        }
        if(ans.size() == 0)
            ans += '/';
        return ans;
    }
};