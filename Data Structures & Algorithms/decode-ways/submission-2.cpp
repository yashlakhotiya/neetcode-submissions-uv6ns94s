class Solution {
public:
    int countdecodings(string &s, int i, vector<int> &dp) {
        if(s[i]=='0') return 0;
        if(i >= s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        string enc1 = s.substr(i, 1);
        int cnt = countdecodings(s, i+1, dp);
        string enc2 = "";
        if(i+1 < s.size()) {
            enc2 = s.substr(i, 2);
            if(stoi(enc2) > 26) enc2 = "";
        }
        if(enc2 != "") cnt += countdecodings(s, i+2, dp);
        return dp[i]=cnt;
    }
    int numDecodings(string s) {
        int dp1=1, dp2=0;
        for(int i=s.size()-1; i>=0; i--) {
            int dp=0;
            if(s[i]=='0') {
                dp = 0;
            } else {
                int cnt = dp1;
                string enc2 = "";
                if(i+1 < s.size()) {
                    enc2 = s.substr(i, 2);
                    if(stoi(enc2) > 26) enc2 = "";
                }
                if(enc2 != "") cnt += dp2;
                dp = cnt;
            }
            dp2 = dp1; dp1 = dp;
        }
        return dp1;
    }
};
