class Solution {
public:
    int dfs(vector<int>& piles, int l, int r, vector<vector<int>> &dp) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int left = piles[l]-dfs(piles,l+1, r, dp);
        int right = piles[r]-dfs(piles, l, r-1, dp);
        return dp[l][r]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        if(dfs(piles, 0, piles.size()-1, dp) > 0) return true;
        else return false;
    }
};