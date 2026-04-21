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
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return partition(nums, 0, target, dp);
    }
};
