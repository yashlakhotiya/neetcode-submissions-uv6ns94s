class Solution {
public:
    int dfs(vector<int>& stones, int i, int total, int stonesum, vector<vector<int>> &dp) {
        int target = (stonesum+1)/2;
        if(total >= target || i >= stones.size()) {
            int secondtotal = stonesum-total;
            return abs(total-secondtotal);
        }
        if(dp[i][total] != -1) return dp[i][total];
        int p = dfs(stones, i+1, total+stones[i], stonesum, dp);
        int np = dfs(stones, i+1, total, stonesum, dp);
        return dp[i][total]=min(p, np);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int stonesum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stonesum+1)/2;
        vector<vector<int>> dp(stones.size()+1, vector<int>(stonesum+1, -1));
        return dfs(stones, 0, 0, stonesum, dp);
    }
};