class Solution {
public:
    int nsq(int n, vector<int> &dp) {
        if(n<=0) return 0;
        if(dp[n] != -1) return dp[n];
        int res = n;
        for(int i=1; i*i<=n; i++) {
            res = min(res, 1+nsq(n-i*i, dp));
        }
        return dp[n]=res;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++) {
            int res = i;
            for(int k=1; k*k<=i; k++) {
                res = min(res, 1+dp[i-k*k]);
            }
            dp[i]=res;
        }
        return dp[n];
    }
};