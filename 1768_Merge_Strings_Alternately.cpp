class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len = min(word1.size(), word2.size());
        int len1 = word1.size();
        int len2 = word2.size();
        string ans = "";
        for(int i = 0; i < len; i++) {
            ans += word1[i];
            ans += word2[i];
        }
        if(len2 > len1)
            for(int i = len; i < len2; i++)
                ans += word2[i];
        else
            for(int i = len; i < len1; i++)
                ans += word1[i];
        return ans;
    }
};