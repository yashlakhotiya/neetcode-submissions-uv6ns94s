class Solution {
public:
    int dfs(vector<int>& nums, int i, int cursum, int target) {
        if (cursum > target) return 0;    // prune
        if (i >= nums.size()) return cursum==target;

        int res = 0;
        if(cursum == target) res += 1;
        for (int k = i; k < nums.size(); k++) {
            res += dfs(nums, k + 1, cursum + nums[k], target);
        }
        return res;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0) return 0;
        int subsettarget = (sum + target) / 2;

        return dfs(nums, 0, 0, subsettarget);
    }
};