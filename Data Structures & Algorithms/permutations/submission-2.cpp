class Solution {
public:
    void backtrack(vector<int> &nums, int idx, vector<vector<int>> &res) {
        if(idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(nums, idx+1, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};
