class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int wsum = 0;
        int res = INT_MAX;
        int l = 0;
        for(int r=0; r<nums.size(); r++) {
           wsum += nums[r];
           while(wsum >= target) {
            res = min(res, r-l+1);
            wsum -= nums[l];
            l++;
           } 
        }
        if(res == INT_MAX) res=0;
        return res;
    }
};