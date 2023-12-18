class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> tmp;
        vector<int> ans(temp.size(), 0);
        int len = temp.size();
        for(int i = 0; i < len; ++i) {
            while(!tmp.empty() && temp[i] > temp[tmp.top()]) {
                ans[tmp.top()] = i - tmp.top();
                tmp.pop();
            } // tmp store the index of temperature, temperature in the stack will be decreasing order(buttom to top)
            tmp.push(i);
        }
        return ans;
    }
};