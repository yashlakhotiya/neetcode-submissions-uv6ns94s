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
        vector<vector<int>> dp(piles.size()+1, vector<int>(piles.size()+1, -1));
        for(int l=piles.size(); l>=0; l--) {
            for(int r=0; r<=piles.size(); r++) {
                if(l >= r) dp[l][r] = 0;
                // if(dp[l][r] != -1) return dp[l][r];
                else {
                    int left = piles[l]-dp[l+1][r];
                    int right = piles[r]-dp[l][r-1];
                    dp[l][r]=max(left,right);
                }
            }
        }
        if(dp[0][piles.size()-1]> 0) return true;
        else return false;
    }
};