class Solution {
public:
    bool ispalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i >= j) return dp[i][j] = true;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = s[i] == s[j] && ispalindrome(s, i+1, j-1, dp);
    }
    string longestPalindrome(string s) {
        string res = "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        for(int L=1; L<=s.size(); L++) {
            for(int i=0; i+L-1 < s.size(); i++) {
                int j = i+L-1;
                if(L == 1) {
                    dp[i][j] = true;
                } else if(L == 2 && s[i]==s[j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = s[i]==s[j]&&dp[i+1][j-1];
                }
                if(dp[i][j] && L > res.size()) {
                    res = s.substr(i, L);
                }
            }
        }
        return res;
    }
};
