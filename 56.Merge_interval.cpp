class Solution {
public:
    int line[200005];
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int index = 1;
        vector<int> reserve;
        vector<vector<int>> ans;
        for(auto i = intervals.begin(); i < intervals.end(); i++) {
            int overlap = -1;
            for(int j = (*i)[0]; j <= (*i)[1]; j++) {
                if(j == (*i)[1] && line[j] != 1)
                    line[j] = 2;
                else
                    line[j] = 1;
            }
            index++;
        }
        for(int j = 0; j < 15; j++)
            cout << line[j] << " ";
        vector<int> bound;
        bool change = true; // can change to other set
        for(int j = 0; j < 200005; j++) {
            if(line[j] == 1 && change == true) {
                bound.push_back(j);
                change = false;
            }
            else if(line[j] == 2) {
                if(change == true)
                    bound.push_back(j);
                bound.push_back(j);
                ans.push_back(bound);
                bound.clear();
                change = true;
            }
        }
        return ans;
    }
};