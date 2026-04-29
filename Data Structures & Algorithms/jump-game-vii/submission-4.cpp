class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int farthest = 0;
        q.push(0);
        while(!q.empty()) {
            int size = q.size();
            while(size-- > 0) {
                int i = q.front(); q.pop();
                if(i == s.size()-1) return true;
                for(int jump=minJump; jump<=maxJump; jump++) {
                    if(i+jump < s.size() && s[i+jump]=='0' && i+jump>farthest) {
                        farthest = i+jump;
                        q.push(i+jump);
                    }
                }
            }
        }
        return false;
    }
};