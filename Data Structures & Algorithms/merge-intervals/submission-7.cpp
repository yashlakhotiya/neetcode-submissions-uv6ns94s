class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if(intervals.empty()) return {};
        vector<vector<int>> res;
        int istart = intervals[0][0], iend = intervals[0][1];
        for(int i=0; i<intervals.size(); i++) {
            int cstart = intervals[i][0], cend = intervals[i][1];
            if(iend < cstart) {
                res.push_back({istart, iend});
                istart = cstart; iend = cend;
            } else {
                iend = max(iend, cend);
            }
            if(i == intervals.size()-1) res.push_back({istart, iend});
        }
        return res;
    }
};
