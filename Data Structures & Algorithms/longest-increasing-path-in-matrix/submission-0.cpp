class Solution {
public:
    vector<int> x={0,1,0,-1}, y={-1,0,1,0};
    int ROWS, COLS;
    int longestIncreasingPath(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1;
        for(int k=0; k<4; k++) {
            int r = i+x[k], c = j+y[k];
            if(r >= 0 && r < ROWS && c >= 0 && c < COLS && matrix[r][c]>matrix[i][j]) {
                res = max(res, 1+longestIncreasingPath(matrix, r, c, dp)); 
            }
        }
        return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> dp(ROWS+1, vector<int>(COLS+1, -1));
        int res = INT_MIN;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                res = max(res, longestIncreasingPath(matrix, i, j, dp));
            }
        }
        return res;
    }
};
