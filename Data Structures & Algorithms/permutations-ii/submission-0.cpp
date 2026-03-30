class Solution {
    vector<vector<int>> res;
    vector<int> perm;
    vector<bool> pick;
public:
    void backtrack(vector<int>& nums) {
        if(perm.size() == nums.size()) {
            res.push_back(perm); return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(pick[i]) {
                continue;
            }

            if(i > 0 && nums[i] == nums[i-1] && !pick[i-1]) continue; 
            perm.push_back(nums[i]);
            pick[i] = true;
            backtrack(nums);
            perm.pop_back();
            pick[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        pick = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return res;
    }
};