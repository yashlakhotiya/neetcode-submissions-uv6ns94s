class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int num: nums) {
            xr ^= num;
        }
        return xr;
    }
};
