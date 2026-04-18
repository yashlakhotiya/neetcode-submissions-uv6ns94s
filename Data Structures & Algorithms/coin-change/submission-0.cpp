class Solution {
public:
    int mini = INT_MAX;
    void coinscount(vector<int> &coins, int coincnt, int i, int amount) {
        if(amount == 0) {
            mini = min(mini, coincnt);
            return;
        }
        if(amount < 0 || i >= coins.size()) {
            return;
        }
        coinscount(coins, coincnt+1, i, amount-coins[i]);
        coinscount(coins, coincnt, i+1, amount);
    }
    int coinChange(vector<int>& coins, int amount) {
        coinscount(coins, 0, 0, amount);
        return mini==INT_MAX?-1:mini;
    }
};
