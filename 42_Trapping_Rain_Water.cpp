// my solution
class Solution {
public:
    pair<int, int> check(vector<int>& height, int st, int st_h) {
        int cnt = 0;
        for(int i = st + 1; i < height.size(); i++) {
            if(height[i] < st_h)
	            cnt += st_h - height[i];
            else 
                return make_pair(cnt, i); // meet the right bound
        }
        if(st_h - 1 >= 0)
            return check(height, st, st_h-1); // no right bound, height - 1
        else
	        return make_pair(cnt, st+1); // not found
    }
    int trap(vector<int>& height) {
        int left = 0, cnt = 0; // left for the index, cnt for the total water
        while(left < height.size()) {
            pair<int, int> result = check(height, left, height[left]);
            cnt += result.first;
            left = result.second; // the next bound that is higher or equal to the original bound
        }
        return cnt;
    }
};

// faster solution
// time: O(n), memory: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int lMax = height[0], rMax = height[height.size()-1];
        int n = height.size();
        int l = 1, r = n-2, ans = 0;
        while(l <= r) {
            if(lMax <= rMax) {
                if(height[l] < lMax) 
                    ans += max(0, min(lMax, rMax) - height[l]);
                else 
                    lMax = height[l];
                l++;
            }
            else {
                if(height[r] < rMax)
                    ans += max(0, min(lMax, rMax) - height[r]);
                else 
                    rMax = height[r];
                r--;
            }
        }
        return ans;
    }
};