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
        vector<int> dp(nums.size()+1, false);
        for(int i=nums.size(); i>=0; i--) {
            if(i == nums.size()-1) dp[i] = true;
            else {
                int jump = nums[i];
                for(int k=1; k<=jump; k++) {
                    int jumpidx = i+k;
                    if(jumpidx < nums.size()) {
                        if(dp[jumpidx]) dp[i]=true;
                    }
                }   
                // dp[i]=false;
            }
        }
        return dp[0];
    }
};
