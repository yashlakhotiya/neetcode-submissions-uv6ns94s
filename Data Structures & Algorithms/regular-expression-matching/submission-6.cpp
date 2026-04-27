class Solution {
public:
    bool ismatch(string &s, string &p, int sind, int pind, vector<vector<int>> &dp) {
        if(sind >= s.size() && pind >= p.size()) return true;
        if(sind < s.size() && pind >= p.size()) return false;
        if(dp[sind][pind] != -1) return dp[sind][pind];    
        if(sind >= s.size()) {
            if(pind+1 < p.size() && p[pind+1] == '*') {
                return dp[sind][pind]=ismatch(s, p, sind, pind+2,dp);
            } else return false;
        }
        if(pind+1 < p.size() && p[pind+1] == '*') {
            return dp[sind][pind]=ismatch(s, p, sind, pind+2,dp) || ((p[pind] == '.' || s[sind]==p[pind]) && (ismatch(s, p, sind+1, pind,dp) || ismatch(s, p, sind+1, pind+2,dp)));
        } else {
            return dp[sind][pind]=(p[pind] == '.' || s[sind]==p[pind]) && ismatch(s, p, sind+1, pind+1,dp);
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return ismatch(s, p, 0, 0, dp);
    }
};
