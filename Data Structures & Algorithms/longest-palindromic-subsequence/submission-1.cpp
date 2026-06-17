class Solution {
public:
    int palindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = 2+palindrome(s, i+1, j-1, dp);
        else {
            return dp[i][j] = max(
                {
                    palindrome(s, i+1, j, dp),
                    palindrome(s, i, j-1, dp)
                }
            );
        }
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int L=1; L<=s.size(); L++) {
            for(int i=0; i+L-1<s.size(); i++) {
                int j = i+L-1;
                if(L == 1) {
                    dp[i][j] = 1;
                } else if(L == 2) {
                    dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                } else {
                    if(s[i] == s[j]) {
                        dp[i][j] = 2+dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};