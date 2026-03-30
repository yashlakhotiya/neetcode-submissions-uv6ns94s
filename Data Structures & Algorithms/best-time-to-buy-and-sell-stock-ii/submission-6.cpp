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
        if(dp[i][allowedToBuy] != -1) return dp[i][allowedToBuy];
        if(allowedToBuy) {
            return dp[i][allowedToBuy]=max(
                 -prices[i]+maxProfitHandler(prices, i+1, 0, dp),
                 0+maxProfitHandler(prices, i+1, 1, dp)
            );
        } else {
            return dp[i][allowedToBuy]=max(
                prices[i]+maxProfitHandler(prices, i+1, 1, dp),
                0+maxProfitHandler(prices, i+1, 0, dp)
            );
        }
    }

    int maxProfitHandler(vector<int>& prices, vector<vector<int>>& dp) {
        for(int allowedToBuy=0; allowedToBuy<=1; allowedToBuy++) {
            for(int i=prices.size()-1; i>=0; i--) {
                if(allowedToBuy) {
                    dp[i][allowedToBuy]=max(
                        -prices[i]+dp[i+1][0],
                        0+dp[i+1][1]
                    );
                } else {
                    dp[i][allowedToBuy]=max(
                        prices[i]+dp[i+1][1],
                        0+dp[i+1][0]
                    );
                }
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,-1));
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        return maxProfitHandler(prices, 0, 1, dp);
    }
};