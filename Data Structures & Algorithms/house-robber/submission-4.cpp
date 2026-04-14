class Solution {
public:
    int rob(vector<int>& nums, int i, vector<int> &dp) {
        if(dp[i] != -1) return dp[i];
        return dp[i]=max(rob(nums, i+1, dp), nums[i]+rob(nums, i+2, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, -1);
        dp[nums.size()] = 0, dp[nums.size()+1] = 0;
        return rob(nums, 0, dp);
    }
};
