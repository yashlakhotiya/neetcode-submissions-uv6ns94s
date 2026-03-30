class Solution {
public:
    void backtrack(vector<int> &nums, vector<int> &perm, vector<bool> &pick, vector<vector<int>> &res) {
        if(perm.size() == nums.size()) {
            res.push_back(perm); return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!pick[i]) {
                perm.push_back(nums[i]);
                pick[i]=true;
                backtrack(nums, perm, pick, res);
                perm.pop_back();
                pick[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<vector<int>> res;
        vector<int> perm;
        backtrack(nums, perm, pick, res);
        return res;
    }
};
