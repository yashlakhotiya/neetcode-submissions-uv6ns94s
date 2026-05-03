class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        return ((n&1)?1:0) + hammingWeight(n>>1);
    }
};
