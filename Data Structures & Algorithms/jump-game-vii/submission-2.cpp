class Solution {
public:
    bool canreach(string &s, int i, int minJump, int maxJump, vector<int> &dp) {
        if(i == s.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int jump=minJump; jump <= maxJump; jump++) {
            if(i+jump < s.size() && s[i+jump] == '0' && canreach(s, i+jump, minJump, maxJump,dp)) return dp[i] = true;
        }
        return dp[i]=false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1] == '1') return false;
        vector<int> dp(s.size()+1, 0);
        for(int i=s.size(); i>=0; i--) {
            if(i == s.size()-1) dp[i] = true;
            else {
                for(int jump=minJump; jump <= maxJump; jump++) {
                    if(i+jump < s.size() && s[i+jump] == '0' && dp[i+jump]==true) {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[0];
    }
};