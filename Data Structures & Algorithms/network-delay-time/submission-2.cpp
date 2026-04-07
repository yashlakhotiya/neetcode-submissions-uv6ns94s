class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adjm(n+1, vector<int>(n+1, 1e9));
        for(auto &v: times) {
            adjm[v[0]][v[1]] = v[2];
        }
        for(int i=1; i<=n; i++) adjm[i][i] = 0;
        for(int k = 1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(adjm[i][k] != 1e9 && adjm[k][j] != 1e9) {
                        adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
                    }
                }
            }
        }
        int res = *max_element(adjm[k].begin()+1, adjm[k].end());
        return (res==1e9)?-1:res;
    }
};
