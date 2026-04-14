class Solution {
public:
    int rob(vector<int>& nums, int i, vector<int> &dp) {
        if(dp[i] != -1) return dp[i];
        return dp[i]=max(rob(nums, i+1, dp), nums[i]+rob(nums, i+2, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, -1);
        dp[n] = dp[n+1] = 0;
        
        for(int i=n-1; i>=0; i--) {
            dp[i]=max(dp[i+1], nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};
