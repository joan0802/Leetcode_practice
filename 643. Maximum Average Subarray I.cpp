class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        double total = 0, ans = -INT_MAX;
        for(int i = 0; i < len; i++) {
            total += nums[i];
            if(i >= (k-1)) {
                // cout << total << endl;
                ans = max(ans, total / k);
                total -= nums[i-k+1];
            }
        }
        return ans;
    }
};