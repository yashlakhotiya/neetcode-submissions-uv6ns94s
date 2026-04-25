class Solution {
public:
    int dfs(vector<int> &nums, int i, int cursum, int target, vector<vector<int>> &dp, int totalsum) {
        if(i >= nums.size()) return cursum==target;
        if(dp[i][cursum+totalsum] != 1e9) return dp[i][cursum+totalsum];
        return dp[i][cursum+totalsum] = dfs(nums, i+1, cursum+nums[i], target, dp, totalsum) + dfs(nums, i+1, cursum-nums[i], target, dp, totalsum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1, vector<int>(2*totalsum+1, 1e9));
        return dfs(nums, 0, 0, target, dp, totalsum);
    }
};
