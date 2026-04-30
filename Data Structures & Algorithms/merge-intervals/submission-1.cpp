class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++) {
            auto it = intervals[i];
            if(res.empty()) res.push_back(it);
            else {
                if(it[0] > res.back()[1]) res.push_back(it);
                else {
                    res.back()[1] = max(res.back()[1], it[1]);
                }
            }
        }
        return res;
    }
};
