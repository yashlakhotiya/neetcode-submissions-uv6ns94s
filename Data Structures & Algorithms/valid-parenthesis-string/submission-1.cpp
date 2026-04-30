class Solution {
public:
    bool isvalid(string &s, int i, int open, vector<vector<int>> &dp) {
        if(i == s.size()) return open==0;
        if(dp[i][open] != -1) return dp[i][open];
        if(open == 0 && s[i]==')') return dp[i][open]=false;
        if(s[i] == ')') return dp[i][open]=isvalid(s, i+1, open-1, dp);
        if(s[i] == '(') return dp[i][open]=isvalid(s, i+1, open+1, dp);
        return dp[i][open]=isvalid(s, i+1, open+1, dp) || isvalid(s, i+1, open, dp) || isvalid(s, i+1, open-1, dp);
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return isvalid(s, 0, 0, dp);
    }
};
