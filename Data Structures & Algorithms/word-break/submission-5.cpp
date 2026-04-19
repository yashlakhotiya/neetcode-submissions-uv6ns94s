class Solution {
public:
    bool findwords(string &s, unordered_set<string>& wordmp, int i, vector<int> &dp) {
        if(i >= s.size()) return true;
        if(dp[i]!=-1) return dp[i]?true:false;
        for(const string &wrd: wordmp) {
            if(i+wrd.size() <= s.size() && s.substr(i, wrd.size()) == wrd){
                if(findwords(s, wordmp, i+wrd.size(), dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordmp(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1, -1);
        return findwords(s, wordmp, 0, dp);
    }
};
