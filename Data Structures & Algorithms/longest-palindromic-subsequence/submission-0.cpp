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
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return palindrome(s, 0, s.size()-1, dp);
    }
};