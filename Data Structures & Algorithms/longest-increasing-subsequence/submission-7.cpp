class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        vector<int> dp(nums.size()+1,1);
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[i] > nums[prev] && 1+dp[prev] > dp[i]) dp[i] = 1+dp[prev];
            }
            if(dp[i] > res) res = dp[i];
        }
        return res;
    }
};