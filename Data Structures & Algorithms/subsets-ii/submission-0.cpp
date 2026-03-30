class Solution {
public:
    set<vector<int>> setres;
    void backtrack(vector<int>& nums, int i, vector<int> &subset) {
        if(i == nums.size()) {
            setres.insert(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset);
        subset.pop_back();
        backtrack(nums, i+1, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, 0, subset);
        vector<vector<int>> res(setres.begin(), setres.end());
        return res;
    }
};
