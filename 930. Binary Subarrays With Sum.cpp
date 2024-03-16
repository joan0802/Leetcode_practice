class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(sum == goal) {
                ans++;
            }
            if(freq.find(sum-goal) != freq.end()) {
                ans += freq[sum-goal];
            }
            freq[sum]++;
        }
        return ans;
    }
};