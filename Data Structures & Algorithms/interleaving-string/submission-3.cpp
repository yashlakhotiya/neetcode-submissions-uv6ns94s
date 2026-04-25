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
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, 0)));
        for(int i=s1.size(); i>=0; i--) {
            for(int j=s2.size(); j>=0; j--) {
                for(int k=s3.size(); k>=0; k--) {
                    if(k == s3.size()) {
                        if(i == s1.size() && j == s2.size()) dp[i][j][k] = true;
                        else dp[i][j][k] = false;
                        continue;
                    }
                    // if(dp[i][j][k] != -1) dp[i][j][k] = dp[i][j][k];
                    bool res = false;
                    if(i < s1.size() && k < s3.size()) {
                        if(s1[i] == s3[k]) res = res || dp[i+1][j][k+1];
                    }
                    if(j < s2.size() && k < s3.size()) {
                        if(!res && s2[j] == s3[k]) res = res || dp[i][j+1][k+1]; 
                    }
                    dp[i][j][k]=res;
                }
            }
        }
        return dp[0][0][0];
    }
};
