class Solution {
    int steps[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        auto getidx = [&](int i, int j) {
            return i*grid[0].size()+j;
        };
        int nofreshoranges = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({getidx(i,j),0});
                }
                if(grid[i][j] == 1) nofreshoranges++;
            }
        }
        int mini = 0;
        while(!q.empty()) {
            auto [cur, t] = q.front(); q.pop();
            int ci = cur/grid[0].size(), cj = cur%grid[0].size();
            mini = max(mini, t);
            for(int k=0; k<4; k++) {
                int ni = ci+steps[k][0], nj = cj+steps[k][1];
                if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size()) continue;
                if(grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    nofreshoranges--;
                    q.push({getidx(ni, nj), t+1});
                }
            }
        }
        return !nofreshoranges?mini:-1;
    }
};
