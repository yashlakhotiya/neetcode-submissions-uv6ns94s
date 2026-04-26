class Solution {
public:
    int count(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        if(j == word2.size()) return (int)word1.size()-i;
        if(i == word1.size()) return (int)word2.size()-j;
        if(dp[i][j] != -1) return dp[i][j];
        int res = word1.size();
        if(word1[i] == word2[j]) {
            res = min(res, count(word1, word2, i+1, j+1, dp));
        }
        res = min(res, 1+count(word1, word2, i, j+1, dp));
        res = min(res, 1+count(word1, word2, i+1, j+1, dp));
        res = min(res, 1+count(word1, word2, i+1, j, dp));
        return dp[i][j]=res;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        vector<int> next(word2.size()+1, 0), curr(word2.size()+1, 0);
        for(int i=word1.size(); i>=0; i--) {
            for(int j=word2.size(); j>=0; j--) {
                if(j == word2.size()) curr[j] = (int)word1.size()-i;
                else if(i == word1.size()) curr[j] = (int)word2.size()-j;
                else {
                    int res = word1.size();
                    if(word1[i] == word2[j]) {
                        res = min(res, next[j+1]);
                    }
                    res = min(res, 1+curr[j+1]);
                    res = min(res, 1+next[j+1]);
                    res = min(res, 1+next[j]);
                    curr[j]=res;
                }
            }
            next = curr;
        }
        return next[0];
    }
};
