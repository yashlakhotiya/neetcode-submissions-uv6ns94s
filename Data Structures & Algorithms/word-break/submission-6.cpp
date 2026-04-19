class Solution {
public:
    bool findwords(string &s, vector<string>& wordDict, int i, vector<int> &dp) {
        if(i >= s.size()) return true;
        if(dp[i]!=-1) return dp[i]?true:false;
        for(const string &wrd: wordDict) {
            if(i+wrd.size() <= s.size() && s.substr(i, wrd.size()) == wrd){
                if(findwords(s, wordDict, i+wrd.size(), dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, -1);
        return findwords(s, wordDict, 0, dp);
    }
};
