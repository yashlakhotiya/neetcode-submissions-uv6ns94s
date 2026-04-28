class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumsofar = nums[0], maxi=nums[0];
        for(int i=1; i<nums.size(); i++) {
            sumsofar = max(nums[i], sumsofar+nums[i]);
            maxi = max(maxi, sumsofar);
        }
        return maxi;
    }
};
