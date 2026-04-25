class Solution {
public:
    int change(vector<int>& coins, int amt, int i, vector<vector<int>> &dp) {
        if(amt == 0) {
            return 1;
        }
        if(i >= coins.size()) return 0;
        if(dp[i][amt] != -1) return dp[i][amt]; 
        dp[i][amt] = change(coins, amt, i+1, dp);
        if(amt-coins[i]>=0) dp[i][amt] += change(coins, amt-coins[i], i, dp);
        return dp[i][amt];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        for(int i=coins.size(); i>=0; i--) {
            for(int amt=0; amt<=amount; amt++) {
                if(amt == 0) {
                    dp[i][amt] = 1;
                }
                else if(i >= coins.size()) dp[i][amt] = 0;
                // if(dp[i][amt] != -1) return dp[i][amt]; 
                else {
                    dp[i][amt] = dp[i+1][amt];
                    if(amt-coins[i]>=0) dp[i][amt] += dp[i][amt-coins[i]];
                }
                // return dp[i][amt];
            }
        }
        return dp[0][amount];
    }
};
