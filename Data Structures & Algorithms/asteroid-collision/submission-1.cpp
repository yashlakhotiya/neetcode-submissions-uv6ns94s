class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int ast : asteroids) {
            if(s.empty()) s.push(ast);
            else {
                bool incomingAstLeft = true;
                while(!s.empty() && s.top() > 0 && ast < 0) {
                    int blast = s.top()+ast;
                    if(blast > 0) {
                        incomingAstLeft = false;
                        break;
                    } else if(blast == 0) {
                        s.pop();
                        incomingAstLeft = false;
                        break;
                    } else s.pop();
                }
                if(incomingAstLeft) s.push(ast);
            }
        }
        vector<int> res;
        while(!s.empty()) {
            res.push_back(s.top()); s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};