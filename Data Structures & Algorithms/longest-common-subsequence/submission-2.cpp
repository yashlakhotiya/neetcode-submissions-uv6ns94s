class Solution {
public:
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return 1+lcs(s1, s2, i+1, j+1, dp);
        else return dp[i][j]=max(lcs(s1, s2, i+1, j, dp), lcs(s1, s2, i, j+1, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        vector<int> curr(s2.size()+1,0), next(s2.size()+1, 0);
        for(int i=s1.size()-1; i>=0; i--) {
            for(int j=s2.size()-1; j>=0; j--) {
                if(i >= s1.size() || j >= s2.size()) curr[j] = 0;
                // if(dp[i][j] != -1) return dp[i][j];
                if(s1[i] == s2[j]) curr[j] = 1+next[j+1];
                else curr[j]=max(next[j], curr[j+1]);
            }
            next = curr;
        }
        return curr[0];
    }
};
