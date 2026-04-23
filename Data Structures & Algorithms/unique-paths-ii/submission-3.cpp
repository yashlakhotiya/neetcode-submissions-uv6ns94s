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
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<int> nextr(n+1, 0), curr(n+1, 0);
        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i < 0 || i >= m || j < 0 || j >= n) curr[j] = 0;
                else if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else if(i == m-1 && j == n-1) curr[j] = 1;
                else curr[j] = nextr[j]+curr[j+1];
            }
            nextr = curr;
        }
        return curr[0];
    }
};