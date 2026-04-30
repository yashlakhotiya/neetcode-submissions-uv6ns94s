class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool intervalused = false;
        for(auto &it: intervals) {
            if(it[1] < newInterval[0]) {
                res.push_back(it);
            } else if(it[0] > newInterval[1]){
                if(!intervalused) {
                    res.push_back(newInterval);
                    intervalused = !intervalused;
                }
                res.push_back(it);
            } else {
                newInterval = {min(it[0], newInterval[0]), max(it[1], newInterval[1])};
            }
        }
        if(!intervalused) res.push_back(newInterval);
        return res;
    }
};
