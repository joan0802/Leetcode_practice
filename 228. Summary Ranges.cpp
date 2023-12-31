class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        int l = nums[0], r = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == r+1) {
                r = nums[i];
            }
            else {
                string tmp = "";
                tmp += to_string(l);
                if(l != r) {
                    tmp += "->";
                    tmp += to_string(r);
                }
                ans.push_back(tmp);
                l = nums[i], r = nums[i];
            }
        }
        string tmp = "";
        tmp += to_string(l);
        if(l != r) {
            tmp += "->";
            tmp += to_string(r);
        }
        ans.push_back(tmp);
        return ans;
    }
};