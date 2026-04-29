class Solution {
public:
    bool canreach(string &s, int i, int min, int max, vector<int> &dp) {
        if(i == s.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int jump=min; jump <= max; jump++) {
            if(i+jump < s.size() && s[i+jump] == '0' && canreach(s, i+jump, min, max,dp)) return dp[i] = true;
        }
        return dp[i]=false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1] == '1') return false;
        vector<int> dp(s.size()+1, -1);
        return canreach(s, 0, minJump, maxJump, dp);
    }
};