class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stonesum = accumulate(stones.begin(), stones.end(), 0);
        int target = (stonesum+1)/2;
        vector<int> curr(stonesum+1, 0), next(stonesum+1, 0);
        for(int i=stones.size(); i>=0; i--) {
            for(int total=stonesum; total>=0; total--) {
                if(total >= target || i >= stones.size()) {
                    int secondtotal = stonesum-total;
                    curr[total] = abs(total-secondtotal);
                } else {
                    int p = next[total+stones[i]];
                    int np = next[total];
                    curr[total]=min(p, np);
                }
            }
            next = curr;
        }
        return next[0];
    }
};