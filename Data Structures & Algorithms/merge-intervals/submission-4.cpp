class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto &it: intervals) {
            int start=it[0], end=it[1];
            mp[start]++; mp[end]--;
        }
        int have=0;
        vector<vector<int>> res;
        vector<int> interval;
        for(auto &[i, count]: mp) {
            if(interval.empty()) {
                interval.push_back(i);
            }
            have += count;
            if(have == 0) {
                interval.push_back(i);
                res.push_back(interval);
                interval.clear();
            }
        }
        return res;
    }
};
