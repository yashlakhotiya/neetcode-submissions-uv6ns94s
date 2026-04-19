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
        int res = nocoins(coins, amount);
        return res==1e9?-1:res;
    }
};
