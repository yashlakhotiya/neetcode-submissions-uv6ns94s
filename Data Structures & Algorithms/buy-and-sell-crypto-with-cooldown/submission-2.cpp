class Solution {
public:
    int maxp(vector<int>& prices, int i, int canbuy, vector<vector<int>> &dp) {
        if(i >= prices.size()) return 0;
        if(dp[i][canbuy] != -1) return dp[i][canbuy];
        int res = 0;
        if(canbuy) {
            res = max(-prices[i]+maxp(prices,i+1,0, dp), maxp(prices, i+1, 1,dp));
        } else {
            res = max(prices[i]+maxp(prices,i+2,1,dp), maxp(prices, i+1, 0,dp));
        }
        return dp[i][canbuy] = res;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int>(2, 0));
        for(int i=prices.size()-1; i>=0; i--) {
            for(int canbuy=1; canbuy>=0; canbuy--) {
                // if(i >= prices.size()) return 0;
                // if(dp[i][canbuy] != -1) return dp[i][canbuy];
                int res = 0;
                if(canbuy) {
                    res = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                } else {
                    res = max(prices[i]+dp[i+2][1], dp[i+1][0]);
                }
                dp[i][canbuy] = res;
            }
        }
        return dp[0][1];
    }
};

