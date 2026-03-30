class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, m=0;
        int res=0;
        while(l <= r) {
            m = l+(r-l)/2;
            if((long long) m*m == x) return m;
            else if((long long) m*m < x) {
                res = m;
                l=m+1;
            }
            else r=m-1;
        }
        return res;
    }
};