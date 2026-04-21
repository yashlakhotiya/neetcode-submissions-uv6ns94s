class Solution {
public:
    bool partition(vector<int> &nums, int i, int target, vector<vector<int>> &dp) {
        if(i >= nums.size()){
            return target == 0;
        }
        if(target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        bool np = partition(nums, i+1, target,dp);
        bool p = partition(nums, i+1, target-nums[i],dp);
        return dp[i][target] = (p || np);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, false));
        // for(int ta)
        for(int i=nums.size(); i>=0; i--) {
            for(int t=target; t>=0; t--) {
                if(i >= nums.size()) dp[i][t] = (t==0);
                else if(t == 0) dp[i][t] = true;
                else {
                    dp[i][t] = dp[i+1][t];
                    if(t-nums[i] >= 0) dp[i][t] |= dp[i+1][t-nums[i]];
                }
            }
        }
        return dp[0][target];
    }
};
