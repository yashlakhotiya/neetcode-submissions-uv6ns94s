class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++) {
            int sum = 0;
            for(int j=i; j<i+nums.size(); j++) {
                sum += nums[j%nums.size()];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};