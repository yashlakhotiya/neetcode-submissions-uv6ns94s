class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = INT_MAX;
        for(int i=left; i<=right; i++) {
            res &= i;
        }
        return res;
    }
};