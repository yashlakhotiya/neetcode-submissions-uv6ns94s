class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++) {
            auto it = intervals[i];
            if(res.empty()) res.push_back(it);
            else {
                auto back = res.back();
                if(it[0] > back[1]) res.push_back(it);
                else {
                    back[1] = max(back[1], it[1]);
                    res.pop_back();
                    res.push_back(back);
                }
            }
        }
        return res;
    }
};
