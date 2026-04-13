class Solution {
public:
    int mincost(vector<int>& cost, int i, vector<int> &dp) {
        if(dp[i] != -1) return dp[i];
        return dp[i]=cost[i]+min(mincost(cost, i+1,dp), mincost(cost, i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        dp[cost.size()] = 0;
        return min(mincost(cost, 0,dp), mincost(cost, 1,dp));
    }
};
