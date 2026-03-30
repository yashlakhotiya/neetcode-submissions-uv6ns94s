class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0, maxi=0;
        for(int w : weights) {
            maxi=max(maxi, w);
            sum += w;
        }
        int l=maxi, r=sum, m=0;
        int res=sum;
        while(l <= r) {
            m = l+(r-l)/2;
            if(isPossible(weights, days, m)) {
                res=m;
                r=m-1;
            } else l=m+1;
        }
        return res;
    }

    bool isPossible(vector<int>& weights, int days, int maxCap) {
        int ndays=1, weightRemaining=maxCap;
        for(int w: weights) {
            if(w <= weightRemaining) weightRemaining -= w;
            else {
                weightRemaining = maxCap;
                weightRemaining -= w;
                ndays++;
                if(ndays > days) return false;
            }
        }
        if(ndays <= days) return true;
        else return false;
    }
};