class Solution {
public:
    void dfs(vector<int> &nums, int i, vector<vector<int>> &res, vector<int> &temp) {
        if(i == nums.size()) {
            vector<int> newv;
            for(int n: temp) newv.push_back(n);
            res.push_back(newv);
            return;
        }
        temp.push_back(nums[i]);
        dfs(nums, i+1, res, temp);
        temp.pop_back();
        dfs(nums, i+1, res, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, 0, res, temp);
        return res;
    }
};
