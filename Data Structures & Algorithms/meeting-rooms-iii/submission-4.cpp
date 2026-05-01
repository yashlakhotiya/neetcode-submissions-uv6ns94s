class Solution {
public:
    int getRoomWithMinEndTime(vector<int> &endtime, int meetstart) {
        int minend = 1e9, minendidx=0;
        for(int i=0; i<endtime.size(); i++) {
            if(endtime[i] < minend) {
                minend = endtime[i];
                minendidx = i;
            }
            if(endtime[i] <= meetstart) {
                return i;
            }
        }
        return minendidx;
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> roomMeetingEndTime(n, 0);
        vector<int> roomMeetingCount(n, 0);
        for(auto &meet : meetings) {
            int meetstart = meet[0], meetend = meet[1];
            int roomidx = getRoomWithMinEndTime(roomMeetingEndTime, meetstart);
            int curmeetendtime = roomMeetingEndTime[roomidx];
            if(curmeetendtime <= meetstart) {
                roomMeetingEndTime[roomidx] = meetend;
                roomMeetingCount[roomidx]++;
            } else {
                int delay = curmeetendtime-meetstart;
                meetend += delay;
                roomMeetingEndTime[roomidx] = meetend;
                roomMeetingCount[roomidx]++;
            }
        }
        return max_element(roomMeetingCount.begin(), roomMeetingCount.end())-roomMeetingCount.begin();
    }
};