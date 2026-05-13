class Solution {
public:
    bool dfs(string &word, unordered_set<string> &wordset, unordered_map<string,int> &dp) {
        if(dp[word] != 0) return dp[word]==1?true:false;
        for(int l=1; l<=word.size()-1; l++) {
            string prefix = word.substr(0, l);
            int j = l;
            string suffix = word.substr(j);
            if(wordset.count(prefix) && (wordset.count(suffix) || dfs(suffix, wordset, dp))) {
                dp[word] = 1;
                return true;
            }
        }
        dp[word]=-1;
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordset(words.begin(), words.end());
        unordered_map<string,int> dp; // 0 means not found. 1 means true, -1 means false
        vector<string> res;
        for(string &word : words) {
            if(dfs(word, wordset, dp)) res.push_back(word);
        }
        return res;
    }
};