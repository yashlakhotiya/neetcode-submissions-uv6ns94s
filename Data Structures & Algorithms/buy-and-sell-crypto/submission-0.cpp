class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSofar = INT_MAX;
        int res = 0;
        for(int i=0; i<prices.size(); i++) {
            minSofar = min(minSofar, prices[i]);
            int sellprice = prices[i];
            res = max(res, sellprice-minSofar);
        }
        return res;
    }
};
