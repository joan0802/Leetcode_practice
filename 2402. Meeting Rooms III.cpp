class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        pair<int, int> ans;
        int booked[105];
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> end; // end time, index
        priority_queue<int, vector<int>, greater<int>> aval;
        for(int i = 0; i < n; i++)
            aval.push(i);
        for(auto cur: meetings) {
            while(!end.empty() && cur[0] >= end.top().first) {
                aval.push(end.top().second);
                end.pop();
            }
            if(!aval.empty()) {
                auto t = aval.top();
                aval.pop();
                booked[t]++;
                end.push({cur[1], t});
            }
            else {
                auto t = end.top();
                end.pop();
                booked[t.second]++;
                end.push({t.first + cur[1] - cur[0], t.second}); // delay
            }
        }
        for(int i = 0; i < n; i++) {
            if(ans.first < booked[i]) {
                ans.first = booked[i];
                ans.second = i;
            }
        }
        return ans.second;
    }
};