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
        return change(amount, coins, 0, dp);
    }
};
