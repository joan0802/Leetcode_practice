// Sol1 -> O(nlogn)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for(auto i: intervals) {
            if(ans.size() == 0) {
                ans.push_back(i);
                continue;
            }
            if(i[0] <= ans.back()[1]) {
                if(i[1] >= ans.back()[1])
                    ans.back()[1] = i[1];
            }
            else // not overlap
                ans.push_back(i);
        }
        return ans;
    }
};

// Sol2 -> O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) { // Non Overlapping intervals before given newInterval
            ans.push_back(intervals[i++]);
        } 
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        } // update overlapping part
        ans.push_back(newInterval);
        while(i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};
