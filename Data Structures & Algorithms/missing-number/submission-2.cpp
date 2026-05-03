class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = nums.size();
        for(int i=0; i<nums.size(); i++) {
            xr = xr ^ nums[i];
            xr = xr ^ i;
        }
        return xr;
    }
};
