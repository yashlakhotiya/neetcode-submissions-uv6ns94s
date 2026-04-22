class Solution {
public:
    int dfs(vector<int>& stoneValue, int i, vector<int> &dp) {
        int n = stoneValue.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int res = stoneValue[i] - dfs(stoneValue, i+1,dp);
        if(i+1 < n)
            res = max(res, stoneValue[i] + stoneValue[i+1] - dfs(stoneValue, i+2,dp));
        if(i+2 < n)
            res = max(res, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dfs(stoneValue, i+3,dp));

        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int curr, n1=0, n2=0, n3=0;
        for(int i=n-1; i>=0; i--) {
            int res = stoneValue[i] - n1;
            if(i+1 < n)
                res = max(res, stoneValue[i] + stoneValue[i+1] - n2);
            if(i+2 < n)
                res = max(res, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - n3);

            curr=res;
            n3 = n2; n2 = n1; n1 = curr;
        }
        int res = curr;
        if(res == 0) return "Tie";
        else if(res < 0) return "Bob";
        else return "Alice";
    }
};