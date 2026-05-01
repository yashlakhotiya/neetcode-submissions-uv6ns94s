class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        auto LI = intervals[0];
        int i=1, count=0;
        while(i < intervals.size()) {
            int le = LI[1];
            int cs = intervals[i][0], ce=intervals[i][1];
            if(le <= cs) {
                LI = intervals[i];
            } else if(ce >= le) {
                count++;
            } else if(le > ce) {
                count++;
                LI = intervals[i];
            }
            i++;
        }
        return count;
    }
};
