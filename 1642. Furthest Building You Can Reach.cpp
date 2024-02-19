class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> jump; // increasing
        for(int i = 0; i < heights.size()-1; ++i) {
            int diff = heights[i+1] - heights[i];
            if(diff > 0) {
                jump.push(diff);
                if(jump.size() > ladders) {
                    int b = jump.top();
                    jump.pop();
                    if(b <= bricks) {
                        bricks -= b;
                    }
                    else
                        return i;
                }
            }
        }
        return heights.size()-1;
    }
};