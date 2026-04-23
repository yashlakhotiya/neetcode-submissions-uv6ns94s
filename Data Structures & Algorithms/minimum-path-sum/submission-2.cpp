class Solution {
public:
    int ROW, COL;
    int minpathsum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        if(i >= ROW || j >= COL) return 1e9;
        if(i==ROW-1 && j==COL-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(minpathsum(grid, i+1, j, dp), minpathsum(grid, i, j+1, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        ROW=grid.size(); COL=grid[0].size();
        vector<vector<int>> dp(ROW, vector<int>(COL, -1));
        return minpathsum(grid, 0, 0, dp);
    }
};