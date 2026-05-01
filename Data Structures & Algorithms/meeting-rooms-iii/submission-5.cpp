class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for(int i=0; i<n; i++) availableRooms.push(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> roomSlots;
        for(auto &meet: meetings) {
            int meetstart = meet[0], meetend = meet[1];
            while(!roomSlots.empty() && roomSlots.top().first <= meetstart) {
                availableRooms.push(roomSlots.top().second);
                roomSlots.pop();
            }
            if(!availableRooms.empty()) {
                int roomidx = availableRooms.top(); availableRooms.pop();
                roomSlots.push({meetend, roomidx});
                count[roomidx]++;
            } else {
                auto roomslot = roomSlots.top(); roomSlots.pop();
                int duration = meetend - meetstart;
                roomslot.first += duration;
                roomSlots.push(roomslot);
                count[roomslot.second]++;
            }
        }
        return max_element(count.begin(), count.end())-count.begin();
    }
};