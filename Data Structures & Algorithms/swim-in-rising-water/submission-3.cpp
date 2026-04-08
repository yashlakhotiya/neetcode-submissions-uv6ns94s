class Solution {
public:
    int x[4] = {0,1,0,-1};
    int y[4] = {-1,0,1,0};
    bool ispossible(vector<vector<int>>& grid, int t, int i, int j, vector<vector<bool>> &visited) {
        int ROWS = grid.size(), COLS=grid[0].size();
        if(i<0 || j<0 || i >= ROWS || j >= COLS || visited[i][j] || grid[i][j] > t) return false;
        if(i==ROWS-1 && j==COLS-1) return true;
        visited[i][j] = true;
        for(int k=0;k<4;k++) {
            int ni = i+x[k], nj=j+y[k];
            if(ispossible(grid, t, ni, nj, visited)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int maxheight = -1e9;
        int minheight = 1e9;
        int n = grid.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                maxheight = max(maxheight, grid[i][j]);
                minheight = min(minheight, grid[i][j]);
            }
        }
        int l = minheight, r = maxheight, m=0;
        int res = 0;
        while(l <= r) {
            m = l+(r-l)/2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(ispossible(grid, m, 0, 0, visited)){
                res = m;
                r = m-1;
            } else {
                l=m+1;
            }
        }
        return res;
    }
};
