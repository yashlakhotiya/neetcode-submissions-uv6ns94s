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
        vector<int> curr(2,0), next(2,0), last(2,0);
        for(int i=prices.size()-1; i>=0; i--) {
            for(int canbuy=1; canbuy>=0; canbuy--) {
                int res = 0;
                if(canbuy) {
                    res = max(-prices[i]+next[0], next[1]);
                } else {
                    res = max(prices[i]+last[1], next[0]);
                }
                curr[canbuy] = res;
            }
            last=next;
            next=curr;
        }
        return next[1];
    }
};

