class Solution {
public:
    bool ismatch(string &s, string &p, int sind, int pind, vector<vector<int>> &dp) {
        if(pind >= p.size()) {
            return sind >= s.size();
        }
        if(dp[sind][pind] != -1) return dp[sind][pind];   
        if(pind+1 < p.size() && p[pind+1] == '*') {
            if(sind >= s.size()) return dp[sind][pind] = ismatch(s, p, sind, pind+2, dp);
            return dp[sind][pind] = ismatch(s, p, sind, pind+2,dp) || 
            ((p[pind] == '.' || s[sind]==p[pind]) && ismatch(s, p, sind+1, pind,dp));
        } else {
            if(sind >= s.size()) return false;
            else return dp[sind][pind] = (p[pind] == '.' || s[sind]==p[pind]) && ismatch(s, p, sind+1, pind+1,dp);
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return ismatch(s, p, 0, 0, dp);
    }
};
