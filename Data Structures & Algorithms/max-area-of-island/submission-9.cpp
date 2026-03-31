class Solution {
public:
    int ROWS=0, COLS=0;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(grid[i][j] != 1) return 0;
        grid[i][j]=2;
        int res = 1;
        if(j+1 < COLS && grid[i][j+1] == 1) res += dfs(grid, i, j+1);
        if(j-1 >= 0 && grid[i][j-1] == 1) res += dfs(grid, i, j-1);
        if(i+1 < ROWS && grid[i+1][j] == 1) res += dfs(grid, i+1, j);
        if(i-1 >=0 && grid[i-1][j] == 1) res += dfs(grid, i-1, j);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int maxi = 0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(grid[i][j] == 1) {
                    maxi = max(maxi, dfs(grid, i,j));
                }
            }
        }
        return maxi;
    }
};
