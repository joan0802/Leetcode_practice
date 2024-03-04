class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        int index = s.size()-1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                cnt++;
                s[i] = '0';
            }
        }
        s[index] = '1';
        cnt--;
        index = 0;
        while(cnt > 0) {
            s[index++] = '1';
            cnt--;
        }
        return s;
    }
};