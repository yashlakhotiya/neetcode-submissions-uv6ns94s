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
        vector<int> dp(s.size()+1, 1);
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]=='0') {
                dp[i] = 0;
                continue;
            }
            string enc1 = s.substr(i, 1);
            int cnt = dp[i+1];
            string enc2 = "";
            if(i+1 < s.size()) {
                enc2 = s.substr(i, 2);
                if(stoi(enc2) > 26) enc2 = "";
            }
            if(enc2 != "") cnt += dp[i+2];
            dp[i]=cnt;
        }
        return dp[0];
    }
};
