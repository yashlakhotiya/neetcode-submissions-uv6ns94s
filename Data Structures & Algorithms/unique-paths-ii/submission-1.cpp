class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &dp) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = dfs(obstacleGrid, i+1, j, dp)+dfs(obstacleGrid, i, j+1, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(obstacleGrid, 0, 0, dp);
    }
};