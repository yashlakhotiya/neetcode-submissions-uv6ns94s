class Solution {
public:
    int numcomb(vector<int>& nums, int target, vector<int> &dp) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int res = 0;
        for(int num: nums) {
            res += numcomb(nums, target-num, dp);
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        for(int t=0; t<=target; t++) {
            if(t == 0) dp[t] = 1;
            else {
                dp[t] = 0;
                for(int num: nums) {
                    if(t-num >= 0) dp[t]+=dp[t-num];
                }
            }
        }
        return dp[target];
    }
};