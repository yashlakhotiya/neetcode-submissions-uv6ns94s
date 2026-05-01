class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        for(int q: queries) {
            int minlength = 1e9;
            for(auto &in: intervals) {
                if(q >= in[0] && q <= in[1] && in[1]-in[0]+1 < minlength) minlength = in[1]-in[0]+1;
            }
            res.push_back(minlength==1e9?-1:minlength);
        }
        return res;
    }
};
