class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m=0;
        int res = -1;
        while(l <= r) {
            m = l+(r-l)/2;
            if(nums[m] == target){
                res = m; break;
            } else if(nums[m] > target) r--;
            else l++;
        }
        return res;
    }
};
