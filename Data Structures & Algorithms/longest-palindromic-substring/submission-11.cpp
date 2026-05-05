class Solution {
public:
    bool ispalindrome(string &s, int l, int r, vector<vector<int>> &dp) {
        if(l >= r) return dp[l][r] = true;
        if(dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = s[l] == s[r] && ispalindrome(s, l+1, r-1, dp);
    }
    string longestPalindrome(string s) {
        string res = "";
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(ispalindrome(s, i, j, dp) && j-i+1 > res.size()) {
                    res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};
