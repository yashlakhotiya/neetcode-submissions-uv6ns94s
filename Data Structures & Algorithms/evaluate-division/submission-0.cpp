class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adjm;
        int n = equations.size();
        for(int i=0; i<n; i++) {
            string num = equations[i][0];
            string den = equations[i][1];
            double value = values[i];
            adjm[num][den] = value;
            adjm[den][num] = 1.0/value;
            adjm[num][num] = 1;
            adjm[den][den] = 1;
        }
        for(auto &[k,denmp]: adjm) {
            for(auto &[i, val]: adjm[k]) {
                for(auto &[j, val]: adjm[k]) {
                    if(!adjm[i].count(j)) {
                        if(adjm[i].count(k) && adjm[k].count(j)) {
                            adjm[i][j] = adjm[i][k] * adjm[k][j];
                        }
                    }
                }
            }
        }
        vector<double> res;
        for(auto &q: queries) {
            string &num = q[0];
            string &den = q[1];
            if(adjm.count(num) != 0 && adjm[num].count(den) != 0) {
                res.push_back(adjm[num][den]);
            } else res.push_back(-1.0);
        }
        return res;
    }
};

// [a] -> [b,4]
// [b] -> [a,1/4], [c, 1]
// [c] -> [b, 1]
// [ab] -> [bc, 3.25]
// [bc] -> [ab, 1/3.25]