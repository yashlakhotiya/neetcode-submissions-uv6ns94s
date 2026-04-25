class Solution {
public:
    int change(int amt, vector<int>& coins, int i,vector<vector<int>> &dp) {
        if(amt == 0) return 1;
        if(amt < 0) return 0;
        if(i >= coins.size()) return 0;
        if(dp[i][amt] != -1) return dp[i][amt];
        int res=0;
        for(int k=i; k<coins.size(); k++) {
            res += change(amt-coins[k], coins, k, dp);
        }
        return dp[i][amt]=res;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        for(int i=coins.size(); i>=0; i--) {
            for(int amt=0; amt <= amount; amt++) {
                if(amt == 0) dp[i][amt] = 1;
                else if(i >= coins.size()) dp[i][amt] = 0;
                // if(dp[i][amt] != -1) dp[i][amt] = dp[i][amt];
                else {
                    int res=0;
                    for(int k=i; k<coins.size(); k++) {
                        if(amt-coins[k] >= 0) res += dp[k][amt-coins[k]];
                    }
                    dp[i][amt]=res;
                }
            }
        }
        return dp[0][amount];
    }
};
