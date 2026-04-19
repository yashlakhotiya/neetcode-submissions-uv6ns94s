class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), INT_MIN));
        for(int L=1; L<=nums.size(); L++) {
            for(int i=0; i+L-1 < nums.size(); i++) {
                int j = i+L-1;
                if(i == j) {
                    dp[i][j] = nums[i];
                } else if(j == i+1) {
                    dp[i][j] = nums[i]*nums[j];
                } else {
                    dp[i][j] = nums[i]*nums[j]*dp[i+1][j-1];
                }
                if(dp[i][j] != INT_MIN && dp[i][j] > res) res = dp[i][j];
            }
        }
        return res;
    }
};
