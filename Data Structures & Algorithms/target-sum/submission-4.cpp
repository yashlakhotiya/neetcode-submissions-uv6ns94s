class Solution {
public:
    int dfs(vector<int> &nums, int i, int cursum, int target, vector<vector<int>> &dp, int totalsum) {
        if(i >= nums.size()) return cursum==target;
        if(dp[i][cursum+totalsum] != 1e9) return dp[i][cursum+totalsum];
        return dp[i][cursum+totalsum] = dfs(nums, i+1, cursum+nums[i], target, dp, totalsum) + dfs(nums, i+1, cursum-nums[i], target, dp, totalsum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        // vector<vector<int>> dp(nums.size()+1, vector<int>(2*totalsum+1,  0));
        vector<int> next(2*totalsum+1, 0), curr(2*totalsum+1, 0);
        for(int i=nums.size(); i>=0; i--) {
            for(int cursum=totalsum; cursum >=-totalsum; cursum--) {
                if(i >= nums.size()) curr[cursum+totalsum] = cursum==target;
                // if(dp[i][cursum+totalsum] != 1e9) return dp[i][cursum+totalsum];
                else curr[cursum+totalsum] = next[cursum+nums[i]+totalsum]+ next[cursum-nums[i]+totalsum];
            }
            swap(next, curr);
        }
        return next[0+totalsum];
    }
};

