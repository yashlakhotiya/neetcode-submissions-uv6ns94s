class Solution {
public:
    int totalpaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j]=totalpaths(i+1, j, m, n, dp) + totalpaths(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i == m-1 && j == n-1) dp[i][j] = 1;
                else if(i == m || j == n) dp[i][j] = 0;
                else {
                    dp[i][j]=dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
