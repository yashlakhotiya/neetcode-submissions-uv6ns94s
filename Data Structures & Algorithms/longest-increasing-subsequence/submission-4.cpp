class Solution {
public:
    int lis(vector<int>& nums, int i, int prev, vector<vector<int>> &dp) {
        if(i >= nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int skip = lis(nums, i+1, prev, dp);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + lis(nums, i+1, i, dp);
        }
        return dp[i][prev+1]=max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return lis(nums, 0, -1, dp);
    }
};