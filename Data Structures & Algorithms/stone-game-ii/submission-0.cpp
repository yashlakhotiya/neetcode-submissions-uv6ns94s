class Solution {
public:
    int alicescore(vector<int>& piles, int i, int m, bool aliceturn, vector<vector<vector<int>>> &dp) {
        if(i >= piles.size()) return 0;
        if(dp[i][m][aliceturn] != -1) return dp[i][m][aliceturn];
        int stones = 0, res = aliceturn?INT_MIN:INT_MAX;
        for(int x=1; x <= min(2*m, (int)piles.size()-i); x++) {
            stones += piles[i+x-1];
            if(aliceturn) {
                res = max(res, stones+alicescore(piles, i+x, max(m,x), !aliceturn, dp));
            } else {
                res = min(res, alicescore(piles, i+x, max(m,x), !aliceturn, dp));
            }
        }
        return dp[i][m][aliceturn]=res;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2,-1)));
        return alicescore(piles, 0, 1, true, dp);
    }
};