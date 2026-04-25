class Solution {
public:
    int count(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = count(s, t, i+1, j, dp);
        if(s[i] == t[j]) {
            res += count(s, t, i+1, j+1, dp);
        }
        return dp[i][j]=res;
    }
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        vector<int> next(t.size()+1, 0), cur(t.size()+1, 0);
        for(int i=s.size(); i>=0; i--) {
            for(int j=t.size(); j>=0; j--) {
                if(j == t.size()) cur[j] = 1;
                else if(i == s.size()) cur[j] = 0;
                // if(dp[i][j] != -1) return dp[i][j];
                else {
                    int res = next[j];
                    if(s[i] == t[j]) {
                        res += next[j+1];
                    }
                    cur[j] = res;
                }
            }
            next = cur;
        }
        return next[0];
    }
};
