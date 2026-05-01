/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.start<b.start;
        });
        for(int i=1; i<intervals.size(); i++) {
            int ps = intervals[i-1].start, pe = intervals[i-1].end;
            int cs = intervals[i].start, ce = intervals[i].end;
            if(!(pe <= cs)) {
                return false;
            }
        }
        return true;
    }
};
