class Solution {
public:
    void dfs(vector<int>& nums, int i, int cursum, int target, vector<int> &subset, vector<vector<int>> &res) {
        if(i == nums.size()) return;
        if(cursum > target) return;
        if(cursum == target) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i, cursum+nums[i], target, subset, res);
        subset.pop_back();
        dfs(nums, i+1, cursum, target, subset, res);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, 0, target, subset, res);
        return res;
    }
};
