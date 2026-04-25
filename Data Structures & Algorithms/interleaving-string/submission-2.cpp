class Solution {
public:
    bool dfs(string &s1, string &s2, string &s, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if(k == s.size()) {
            if(i == s1.size() && j == s2.size()) return true;
            else return false;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        bool res = false;
        if(i < s1.size() && k < s.size()) {
            if(s1[i] == s[k]) res = res || dfs(s1, s2, s, i+1, j, k+1, dp);
        }
        if(j < s2.size() && k < s.size()) {
            if(!res && s2[j] == s[k]) res = res || dfs(s1, s2, s, i, j+1, k+1, dp); 
        }
        return dp[i][j][k]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return dfs(s1, s2, s3, 0, 0, 0, dp);
    }
};
