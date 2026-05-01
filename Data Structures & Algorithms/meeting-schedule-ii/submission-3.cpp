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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> events;
        for(auto &interval: intervals) {
            events[interval.start] += 1;
            events[interval.end] -=1;
        }
        int minrooms = 0;
        int currooms = 0;
        for(auto &[i, delta]: events) {
            currooms += delta;
            if(currooms > minrooms) minrooms = currooms;
        }
        return minrooms;
    }
};
