class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(3,0);
        dp[1] = dp[2] = 1;
        if(n < 2) return dp[n];
        for(int i=3; i<=n; i++) {
            int temp = dp[0]+dp[1]+dp[2];
            dp[0] = dp[1]; dp[1] = dp[2]; dp[2] = temp;
        }
        return dp[2];
    }
};