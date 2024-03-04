class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int s = 0, e = tokens.size()-1;
        int cnt = 0, ans = 0;
        while(s <= e) {
            ans = max(ans, cnt);
            if(power >= tokens[s]) {
                power -= tokens[s];
                s++;
                cnt++;
            }
            else if(ans > 0) {
                power += tokens[e];
                e--;
                cnt--;
            }
            else
                break;
        }
        return max(ans, cnt);
    }
};