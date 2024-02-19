class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 0, cnt = 0;
        int len = nums.size();
        vector<int> ans(len);
        while(pos < len || neg < len) {
            while(pos < len && nums[pos] < 0)
                pos++;
            while(neg < len && nums[neg] > 0)
                neg++;
            if(pos < len)
                ans[cnt++] = nums[pos++];
            if(neg < len)
                ans[cnt++] = nums[neg++];
        }
        return ans;
    }
};