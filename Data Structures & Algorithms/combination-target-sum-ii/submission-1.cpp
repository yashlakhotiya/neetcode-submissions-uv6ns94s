class Solution {
public:
    void dfs(vector<int> &nums, int i, int cursum, int target, vector<int> &subset, set<vector<int>> &res) {
        if(cursum == target) {
            res.insert(subset);
            return;
        }
        if(i == nums.size()) return;
        if(cursum > target) return;
        subset.push_back(nums[i]);
        dfs(nums, i+1, cursum+nums[i], target, subset,res );
        subset.pop_back();
        dfs(nums, i+1, cursum, target, subset,res );
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, target, subset, res);
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};
