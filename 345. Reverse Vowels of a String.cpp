class Solution {
public:
    string reverseVowels(string s) {
        string vol = "";
        string table = "aeiouAEIOU";
        int len = s.length(), index = 0;
        for(auto c: s) {
            if(table.find(c) != -1)
                vol += c;
        }
        for(int i = len-1; i >= 0; i--) {
            if(table.find(s[i]) != -1){
                s[i] = vol[index++];
            }
        }
        return s;
    }
};