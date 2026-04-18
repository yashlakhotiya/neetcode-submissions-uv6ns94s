class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string res = "";
        for(int L=1; L<=s.size(); L++) {
            for(int i=0; i+L-1 < s.size(); i++) {
                int j = i+L-1;
                if(i==j) {
                    dp[i][j] = true;
                } else if(j == i+1) {
                    dp[i][j] = s[i]==s[j];
                } else {
                    dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
                }
                if(dp[i][j] && L > res.size()) res = s.substr(i, L);
            }
        }
        return res;
    }
};
