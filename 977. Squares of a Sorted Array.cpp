class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int s = 0, e = n-1;
        for(int i = n - 1; i >= 0; --i) {
            if(abs(nums[s]) >= abs(nums[e])) {
                ans[i] = nums[s] * nums[s];
                s++;
            }
            else {
                ans[i] = nums[e] * nums[e];
                e--;
            }
        }
        return ans;
    }
};