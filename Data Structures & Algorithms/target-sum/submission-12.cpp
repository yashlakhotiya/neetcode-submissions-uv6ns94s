class Solution {
public:
    int dfs(vector<int> &nums, int i, int cursum, int subsettarget) {
        if(i >= nums.size()) return subsettarget==cursum;
        if(subsettarget<0) return 0;
        return dfs(nums, i+1, cursum+nums[i], subsettarget)+dfs(nums,i+1, cursum, subsettarget);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        if((target+totalsum)%2 != 0) return 0;
        int subsettarget = (target+totalsum)/2;
        return dfs(nums, 0, 0, subsettarget);
    }
};

