class Solution {
public:
    void dfs(int i, int n, int k, vector<vector<int>> &res, vector<int> &subset) {
        if(subset.size() > k) return;
        if(i == n+1) {
            if(subset.size() == k) {
                res.push_back(subset);
            }
            return;
        }
        // if(subset.size() == k) {
        //     res.push_back(subset);
        //     return;
        // }
        subset.push_back(i);
        dfs(i+1, n, k, res, subset);
        subset.pop_back();
        dfs(i+1, n, k, res, subset);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(1, n, k, res, subset);
        return res;
    }
};