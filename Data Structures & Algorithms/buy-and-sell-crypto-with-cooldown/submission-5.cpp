class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> curr(2,0), next(2,0), last(2,0);
        int nextsell = 0, nextbuy = 0, lastbuy = 0, curbuy = 0, cursell = 0;
        for(int i=prices.size()-1; i>=0; i--) {
            for(int canbuy=1; canbuy>=0; canbuy--) {
                // int res = 0;
                if(canbuy) {
                    curbuy = max(-prices[i]+nextsell, nextbuy);
                } else {
                    cursell = max(prices[i]+lastbuy, nextsell);
                }
                // curr[canbuy] = res;
            }
            lastbuy = nextbuy;
            nextbuy = curbuy;
            nextsell = cursell;
        }
        return nextbuy;
    }
};

