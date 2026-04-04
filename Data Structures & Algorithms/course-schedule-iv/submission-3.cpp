class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adjm(n, vector<bool>(n, false));
        for(auto &p: prerequisites) {
            adjm[p[0]][p[1]] = true;
        }
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    adjm[i][j] = adjm[i][j] || (adjm[i][k] && adjm[k][j]);
                }
            }
        }
        vector<bool> res;
        for(auto &q: queries) {
            res.push_back(adjm[q[0]][q[1]]);
        }
        return res;
    } 
};