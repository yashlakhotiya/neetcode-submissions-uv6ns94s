class Solution {
public:
    bool ispalindrome(string s, int i, int j, vector<vector<int>> &dp) {
        if(i >= j) return true;
        if(s[i] != s[j]) return false;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j]=ispalindrome(s, i+1, j-1, dp);
    }
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<s.size(); j++) {
                if(i >= j) dp[i][j] = 1;
                else if(s[i] != s[j]) dp[i][j] = 0;
            }
        }
        string res = "";
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(ispalindrome(s, i, j, dp)) {
                    if(j-i+1 > res.size()) res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};
