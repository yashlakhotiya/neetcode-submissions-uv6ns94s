class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, false);
        dp[s.size()] = true;
        for(int i=s.size()-1; i>=0; i--) {
            for(const string &wrd: wordDict) {
                if(i+wrd.size() <= s.size() && s.substr(i, wrd.size())==wrd) {
                    if(dp[i+wrd.size()]) dp[i]=true;
                }
            }
        }
        return dp[0];
    }
};
