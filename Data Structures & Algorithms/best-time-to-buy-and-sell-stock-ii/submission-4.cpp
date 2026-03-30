class Solution {
    int maxProfitHandler(vector<int>& prices, int i, int allowedToBuy) {
        if(i == prices.size()) return 0;
        if(allowedToBuy) {
            return max(
                -prices[i]+maxProfitHandler(prices, i+1, false),
                0+maxProfitHandler(prices, i+1, true)
            );
        } else {
            return max(
                prices[i]+maxProfitHandler(prices, i+1, true),
                0+maxProfitHandler(prices, i+1, false)
            );
        }
    }

    int maxProfitHandler(vector<int>& prices, int i, int allowedToBuy, vector<vector<int>>& dp) {
        if(dp[allowedToBuy][i] != -1) return dp[allowedToBuy][i];
        if(allowedToBuy) {
            return dp[allowedToBuy][i]=max(
                 -prices[i]+maxProfitHandler(prices, i+1, false, dp),
                 0+maxProfitHandler(prices, i+1, true, dp)
            );
        } else {
            return dp[allowedToBuy][i]=max(
                prices[i]+maxProfitHandler(prices, i+1, true, dp),
                0+maxProfitHandler(prices, i+1, false, dp)
            );
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1,-1));
        dp[0][prices.size()] = dp[1][prices.size()] = 0;
        return maxProfitHandler(prices, 0, 1, dp);
    }
};