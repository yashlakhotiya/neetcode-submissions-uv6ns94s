class Solution {
public:
    bool findwords(string &s, unordered_set<string>& wordmp, int i, vector<int> &dp) {
        if(i >= s.size()) return true;
        if(dp[i]!=-1) return dp[i]?true:false;
        for(int j=i; j<s.size(); j++) {
            int L = j-i+1;
            string word = s.substr(i, L);
            if(wordmp.count(word)) {
                if(findwords(s, wordmp, j+1, dp)) return dp[i]=true;
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
