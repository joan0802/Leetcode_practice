class Solution {
public:
    string table[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void backTrack(int index, string digits, string cur) {
        if(index == digits.length()) {
            ans.push_back(cur);
            return;
        }
        for(auto c: table[digits[index]-2-'0']) {
            backTrack(index+1, digits, cur+c);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return ans;
        backTrack(0, digits, "");
        return ans;
    }
};