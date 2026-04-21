class Solution {
public:
    int maximise(int n, vector<int> &dp) {
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int maxi = 1*(n-1);
        for(int i=1; i<=n-1; i++) {
            maxi = max(maxi, i*max(n-i, maximise(n-i, dp)));
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return maximise(n, dp);
    }
};