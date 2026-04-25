class Solution {
public:
    int dfs(vector<int>& piles, int l, int r, vector<vector<int>> &dp) {
        if(l == r) return piles[l];
        if(dp[l][r] != -1) return dp[l][r];
        int left = piles[l]-dfs(piles,l+1, r, dp);
        int right = piles[r]-dfs(piles, l, r-1, dp);
        return dp[l][r]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        vector<int> next(piles.size()+1, 0), cur(piles.size()+1, 0);
        for(int l=piles.size()-1; l>=0; l--) {
            for(int r=l; r<piles.size(); r++) {
                if(l == r) cur[r] = piles[l];
                // if(dp[l][r] != -1) return dp[l][r];
                else {
                    int left = piles[l]-next[r];
                    int right = piles[r]-cur[r-1];
                    cur[r]=max(left,right);
                }
            }
            next = cur;
        }
        if(next[piles.size()-1] > 0) return true;
        else return false;
    }
};