class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1]<b[1];
        });
        int count=0, prevend=intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            int cs = intervals[i][0], ce = intervals[i][1];
            if(cs < prevend) {
                count++;
            } else {
                prevend = intervals[i][1];
            }
        }
        return count;
    }
};
