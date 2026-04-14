class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2, 0);
        
        for(int i=n-1; i>=0; i--) {
            int temp=max(dp[0], nums[i]+dp[1]);
            dp[1] = dp[0]; dp[0] = temp;
        }
        return dp[0];
    }
};
