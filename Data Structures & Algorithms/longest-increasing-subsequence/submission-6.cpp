class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        vector<int> next(nums.size()+1,0), curr(nums.size()+1, 0);
        for(int i=nums.size()-1; i>=0; i--) {
            for(int prev=i-1; prev>=-1; prev--) {
                int skip = next[prev+1];
                int take = 0;
                if(prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + next[i+1];
                }
                curr[prev+1]=max(take, skip);
            }
            next = curr;
        }
        return curr[0];
    }
};