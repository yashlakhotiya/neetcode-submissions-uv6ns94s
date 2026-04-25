class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=s1.size(); i>=0; i--) {
            for(int j=s2.size(); j>=0; j--) {
                int k = i+j;
                if(k == s3.size()) {
                    if(i == s1.size() && j == s2.size()) dp[i][j] = true;
                    else dp[i][j] = false;
                    continue;
                }
                // if(dp[i][j][k] != -1) dp[i][j][k] = dp[i][j][k];
                bool res = false;
                if(i < s1.size() && k < s3.size()) {
                    if(s1[i] == s3[k]) res = res || dp[i+1][j];
                }
                if(j < s2.size() && k < s3.size()) {
                    if(!res && s2[j] == s3[k]) res = res || dp[i][j+1]; 
                }
                dp[i][j]=res;
            }
        }
        return dp[0][0];
    }
};
