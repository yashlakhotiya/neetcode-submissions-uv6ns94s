class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for(int pile: piles) {
            maxi=max(pile, maxi);
        }
        int l=1, r=maxi, m=0;
        int res = maxi;
        while(l<=r) {
            m=l+(r-l)/2;
            if(canEatWithinTime(piles, h, m)){
                res = m;
                r = m-1;
            } else l = m+1;
        }
        return res;
    }

    bool canEatWithinTime(vector<int>& piles, int h, int k) {
        int timeReqd=0;
        for(int pile: piles) {
            timeReqd += ceil(double(pile)/k);
            if(timeReqd > h) return false;
        }
        if(timeReqd <= h) return true;
        return false;
    }
};
