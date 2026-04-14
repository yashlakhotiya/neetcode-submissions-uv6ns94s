class Solution {
public:
    int rob(vector<int>& nums, int i, bool canrob, vector<vector<int>> &dp) {
        if(dp[i][canrob] != -1) return dp[i][canrob];
        int withoutrob = rob(nums, i+1, true,dp);
        int withrob = -1;
        if(canrob) withrob = nums[i] + rob(nums, i+1, false,dp);
        return dp[i][canrob]=max(withrob, withoutrob);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));
        dp[nums.size()][0] = dp[nums.size()][1] = 0;
        return rob(nums, 0, true, dp);
    }
};
