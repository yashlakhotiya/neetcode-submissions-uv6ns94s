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
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        for(int i=nums.size()-1; i>=0; i--) {
            for(int prev=i-1; prev>=-1; prev--) {
                int skip = dp[i+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][prev+1]=max(take, skip);
            }
        }
        return dp[0][0];
    }
};