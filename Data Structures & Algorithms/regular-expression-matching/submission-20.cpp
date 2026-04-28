class Solution {
public:
    bool ismatch(string &s, string &p, int sind, int pind, vector<vector<int>> &dp) {
        if(pind >= p.size()) {
            return sind >= s.size();
        }
        if(dp[sind][pind] != -1) return dp[sind][pind];   
        bool res = false;
        if(pind+1 < p.size() && p[pind+1] == '*') {
            if(sind >= s.size()) res = ismatch(s, p, sind, pind+2, dp);
            else res = ismatch(s, p, sind, pind+2,dp) || 
            ((p[pind] == '.' || s[sind]==p[pind]) && ismatch(s, p, sind+1, pind,dp));
        } else {
            if(sind >= s.size()) res = false;
            else res = dp[sind][pind] = (p[pind] == '.' || s[sind]==p[pind]) && ismatch(s, p, sind+1, pind+1,dp);
        }
        return dp[sind][pind] = res;
    }
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        vector<int> curr(p.size()+1, 0), next(p.size()+1, 0);
        for(int sind=s.size(); sind>=0; sind--) {
            for(int pind=p.size(); pind>=0; pind--) {
                if(pind >= p.size()) {
                    curr[pind] = (sind >= s.size());
                }
                // else if(dp[sind][pind] != -1) dp[sind][pind] = dp[sind][pind];   
                else {
                    bool res = false;
                    if(pind+1 < p.size() && p[pind+1] == '*') {
                        if(sind >= s.size()) res = curr[pind+2];
                        else res = curr[pind+2] || 
                        ((p[pind] == '.' || s[sind]==p[pind]) && next[pind]);
                    } else {
                        if(sind >= s.size()) res = false;
                        else res = (p[pind] == '.' || s[sind]==p[pind]) && next[pind+1];
                    }
                    curr[pind] = res;
                }
            }
            next = curr;
        }
        return next[0];
    }
};
