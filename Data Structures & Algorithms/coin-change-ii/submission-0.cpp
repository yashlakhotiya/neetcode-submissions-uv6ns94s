class Solution {
public:
    int change(vector<int>& coins, int amount, int i, vector<vector<int>> &dp) {
        if(amount == 0) {
            return 1;
        }
        if(i >= coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount]; 
        if(amount < 0) return 0;
        dp[i][amount] = change(coins, amount, i+1, dp);
        if(amount-coins[i]>=0) dp[i][amount] += change(coins, amount-coins[i], i, dp);
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return change(coins, amount, 0, dp);
    }
};
