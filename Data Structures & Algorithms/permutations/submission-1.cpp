class Solution {
public:
    void backtrack(vector<int> &nums, int fixedidx, vector<vector<int>> &res) {
        if(fixedidx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=fixedidx; i<nums.size(); i++) {
            swap(nums[fixedidx], nums[i]);
            backtrack(nums, fixedidx+1, res);
            swap(nums[fixedidx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};
