class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m=0;
        while(l <= r) {
            m = l+(r-l)/2;
            if(nums[m] == target) return m;
            else if(nums[l] == target) return l;
            else if(nums[r] == target) return r;
            else if(nums[l] < nums[m] && target > nums[l] && target < nums[m]) r = m-1;
            else if(nums[l] < nums[m] && !(target > nums[l] && target < nums[m])) l=m+1;
            else if(nums[m] < nums[r] && target > nums[m] && target < nums[r]) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};
