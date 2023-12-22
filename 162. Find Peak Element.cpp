class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;
        int cur = left + (right-left) / 2;
        while(left <= right) {
            cur = left + (right-left) / 2;
            if(cur-1 >= 0 && nums[cur] < nums[cur-1])
                right = cur-1;
            else if(cur+1 < len && nums[cur] < nums[cur+1])
                left = cur+1;
            else
                return cur;
        }
        return left;
    }
};
// Binary Search
// time complexity: O(logn) 
// memory complexity: O(1)