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
                 -prices[i]+maxProfitHandler(prices, i+1, 0, dp),
                 0+maxProfitHandler(prices, i+1, 1, dp)
            );
        } else {
            return dp[allowedToBuy][i]=max(
                prices[i]+maxProfitHandler(prices, i+1, 1, dp),
                0+maxProfitHandler(prices, i+1, 0, dp)
            );
        }
    }

    int maxProfitHandler(vector<int>& prices, vector<vector<int>>& dp) {
        for(int allowedToBuy=0; allowedToBuy<=1; allowedToBuy++) {
            for(int i=prices.size()-1; i>=0; i--) {
                if(allowedToBuy) {
                    dp[allowedToBuy][i]=max(
                        -prices[i]+dp[0][i+1],
                        0+dp[1][i+1]
                    );
                } else {
                    dp[allowedToBuy][i]=max(
                        prices[i]+dp[1][i+1],
                        0+dp[0][i+1]
                    );
                }
            }
        }
        return dp[1][0];
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1,-1));
        dp[0][prices.size()] = dp[1][prices.size()] = 0;
        return maxProfitHandler(prices, 0, 1, dp);
    }
};