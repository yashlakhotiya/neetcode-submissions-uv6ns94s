class Solution {
public:
    int noOfSubarrays(vector<int>& nums, int maxSum) {
        int curSum=0;
        int numOfSubarrays = 1;
        for(int i=0; i<nums.size(); i++) {
            if(curSum+nums[i] <= maxSum) {
                curSum += nums[i];
            } else {
                curSum = nums[i];
                numOfSubarrays++;
            }
        }
        return numOfSubarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi = nums[0], sum=0;
        for(int num : nums) {
            maxi = max(maxi, num);
            sum += num;
        }
        int l = maxi, r=sum, m=0;
        int res = INT_MAX;

        while(l <= r) {
            m = l+(r-l)/2;
            if(noOfSubarrays(nums, m) <= k) {
                res = min(res, m);
                r=m-1;
            } else l=m+1;
        }

        return res;
    }
};