class Solution {
public:
    int minjumps(vector<int> &nums, int i, vector<int> &dp) {
        if(i == nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        int minjumpsres = 1e9;
        for(int j=1; j<=nums[i]; j++) {
            if(i+j < nums.size()) {
                minjumpsres = min(minjumpsres, 1+minjumps(nums, i+j, dp));
            }
        }
        return dp[i]=minjumpsres;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        for(int i=nums.size(); i>=0; i--) {
            if(i == nums.size()-1) dp[i] = 0;
            // if(dp[i] != -1) return dp[i];
            else {
                int minjumpsres = 1e9;
                for(int j=1; j<=nums[i]; j++) {
                    if(i+j < nums.size()) {
                        minjumpsres = min(minjumpsres, 1+dp[i+j]);
                    }
                }
                dp[i]=minjumpsres; 
            }
        }
        return dp[0];
    }
};
