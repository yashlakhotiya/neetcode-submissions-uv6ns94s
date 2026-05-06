class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> events;
        for(auto &in: intervals) {
            events[in[0]]++;
            events[in[1]]--;
        }
        int eventstart=-1, eventend=-1, noactiveintervals=0;
        vector<vector<int>> res;
        for(auto &[k, v]: events) {
            if(eventstart == -1) eventstart = k;
            noactiveintervals += v;
            if(noactiveintervals == 0) {
                eventend = k;
                res.push_back({eventstart, eventend});
                eventstart = -1, eventend = -1;
            }
        }
        return res;
    }
};
