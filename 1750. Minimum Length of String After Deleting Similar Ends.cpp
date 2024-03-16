class Solution {
public:
    int minimumLength(string s) {
        int st = 0, ed = s.size()-1;
        while(st < ed) {
            if(s[st] != s[ed])
                break;
            while(st < ed && s[st+1] == s[st]) {
                st++;
            }
            while(st < ed && s[ed-1] == s[ed]) {
                ed--;
            }
            st++, ed--;
        }
        return st <= ed ? ed-st+1 : 0;
    }
};