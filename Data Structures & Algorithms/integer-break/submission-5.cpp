class Solution {
public:
    int findmaxprod(int n, vector<int> &dp) {
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int maxp = INT_MIN;
        for(int i=1; i<n; i++) {
            maxp = max(maxp, i*(n-i));
            int prod = i*findmaxprod(n-i, dp);
            maxp = max(maxp, prod);
        }
        return dp[n]=maxp;
    } 
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return findmaxprod(n, dp);
    }
};
