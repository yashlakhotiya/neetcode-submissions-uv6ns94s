class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxval = 0;
        for(auto &it: intervals) {
            maxval = max(maxval,  it[0]);
        }
        vector<int> mp(maxval+1, -1);
        for(auto &it: intervals) {
            mp[it[0]] = max(mp[it[0]], it[1]);
        }
        vector<vector<int>> res;
        int curend=-1;
        int curstart=-1;
        for(int i=0; i<mp.size(); i++) {
            if(mp[i]!=-1) {
                if(curstart == -1) curstart = i;
                curend = max(curend, mp[i]);
            }
            if(i == curend) {
                res.push_back({curstart, curend});
                curstart=-1; curend=-1;
            }
        }
        if(curstart != -1) {
            res.push_back({curstart, curend});
        }
        return res;
    }
};
