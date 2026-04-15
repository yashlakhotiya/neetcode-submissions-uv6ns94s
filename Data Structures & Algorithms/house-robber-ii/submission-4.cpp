class Solution {
public:
    int rob(vector<int> nums, int i, bool firstindexused, vector<vector<int>> &dp) {
        if(firstindexused && i >= nums.size()-1) return 0;
        if(!firstindexused && i >= nums.size()) return 0;
        if(dp[i][firstindexused] != -1) return dp[i][firstindexused];
        return dp[i][firstindexused] = max(rob(nums, i+1, firstindexused,dp), nums[i] + rob(nums, i+2, firstindexused, dp));
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return max(rob(nums, 1, false, dp), rob(nums, 0, true, dp));
    } 
};