class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int s1 = 1, s2 = 1, s = s1+s2;
        for(int i=2; i<=n; i++) {
            s = s1+s2;
            s1 = s2;
            s2 = s;
        }
        return s;
    }
};
