class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> f1(26, 0), f2(26, 0);
        vector<int> s1(26, 0), s2(26, 0);
        for(int i = 0; i < word1.size(); i++) {
            s1[word1[i] - 'a'] = 1;
            s2[word2[i] - 'a'] = 1;
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        if(s1 != s2)
            return false;
        if(f1 != f2)
            return false;
        return true;
    }
};