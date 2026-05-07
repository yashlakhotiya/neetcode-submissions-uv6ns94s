class Solution {
public:
    int totalpaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1) return 1;
        if(i < 0 || j<0 || i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j]=totalpaths(i+1, j, m, n, dp) + totalpaths(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return totalpaths(0,0,m,n,dp);
    }
};
