class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i=0, j=1;
        int count = 0;
        while(j < intervals.size()) {
            int cs = intervals[i][0], ce = intervals[i][1];
            int ns = intervals[j][0], ne = intervals[j][1];
            if(ce <= ns) {
                i=j; j++;
            } else if(ce <= ne) {
                j++; count++;
            } else if(ce > ne) {
                i=j; j++; count++;
            }
        }
        return count;
    }
};
