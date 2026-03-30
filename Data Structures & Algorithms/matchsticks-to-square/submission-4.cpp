class Solution {
public:
    bool ispossible(vector<int>& matchsticks, int i, vector<int> &sides, int targetside) {
        if(i==matchsticks.size()) {
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]) return true;
            return false;
        }
        for(int k=0; k<sides.size(); k++) {
            if(sides[k] + matchsticks[i] <= targetside) {
                sides[k] += matchsticks[i];
                if(ispossible(matchsticks, i+1, sides, targetside)) return true;
                sides[k] -= matchsticks[i];
            }
            if(sides[k]==0) return false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4 != 0) return false;
        int targetside = sum/4;
        vector<int> sides(4, 0);
        return ispossible(matchsticks, 0, sides, targetside);
    }
};