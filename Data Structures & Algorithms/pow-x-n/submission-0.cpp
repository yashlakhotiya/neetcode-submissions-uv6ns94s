class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        for(int i=0; i<abs(n); i++) {
            res*=x;
        }
        return n>=0?res:1.0/res;
    }
};
