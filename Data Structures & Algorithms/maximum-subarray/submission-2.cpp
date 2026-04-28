class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumsofar = 0, maxi=nums[0];
        for(int num: nums) {
            if(sumsofar < 0) sumsofar = 0;
            sumsofar += num;
            maxi = max(maxi,sumsofar);
        }
        return maxi;
    }
};
