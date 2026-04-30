class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res = {0,0,0};
        for(int i=0; i<triplets.size(); i++) {
            auto trip = triplets[i];
            if(trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2]) continue;
            res[0] = max(res[0], trip[0]);
            res[1] = max(res[1], trip[1]);
            res[2] = max(res[2], trip[2]);
        }
        return res[0]==target[0] && res[1]==target[1] && res[2] == target[2];
    }
};
