class Solution {
public:
    bool isPalindrome(string &word) {
        int l = 0, r = word.size()-1;
        while(l <= r) {
            if(word[l] == word[r]) {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word: words) {
            if(isPalindrome(word))
                return word;
        }
        return "";
    }
};