class Solution {
public:
vector<int> dp;
    int nocoins(vector<int> &coins, int amount) {
        if(amount == 0) return 0;
        int res = 1e9;
        if(dp[amount] != -1) return dp[amount];
        for(int coin : coins) {
            if(amount-coin<0) continue;
            int temp = nocoins(coins, amount-coin);
            if(temp == 1e9) continue;
            res = min(res, 1+temp);
        }
        return dp[amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1, -1);
        dp[0]=0;
        for(int amt=1; amt<dp.size(); amt++) {
            int res = 1e9;
            for(int coin : coins) {
                if(amt-coin<0) continue;
                int temp = dp[amt-coin];
                if(temp == -1) continue;
                res = min(res, 1+temp);
            }
            if(res != 1e9) dp[amt]=res;
        }
        // int res = nocoins(coins, amount);
        return dp[amount];
    }
};
