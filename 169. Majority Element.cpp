class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, freq = 0;
        for(auto n: nums) {
            if(freq == 0) {
                maj = n;
                freq = 1;
            }
            else if(n != maj)
                freq--;
            else
                freq++;
        }
        return maj;
    }
};