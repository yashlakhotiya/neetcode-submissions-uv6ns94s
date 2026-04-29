class Solution {
public:
    bool canjump(vector<int> &nums, int i, vector<int> dp) {
        if(i == nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        int jump = nums[i];
        for(int k=1; k<=jump; k++) {
            int jumpidx = i+k;
            if(jumpidx < nums.size()) {
                if(canjump(nums, jumpidx, dp)) return dp[i]=true;
            }
        }   
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return canjump(nums, 0, dp);
    }
};
