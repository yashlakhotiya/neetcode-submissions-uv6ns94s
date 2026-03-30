class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int i, vector<int> &subset) {
        if(i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset);
        subset.pop_back();

        while(i+1 < nums.size() && nums[i+1] == nums[i]) {
            i = i+1;
        }
        backtrack(nums, i+1, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, 0, subset);
        return res;
    }
};
