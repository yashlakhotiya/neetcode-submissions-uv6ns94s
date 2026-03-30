class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m=0;
        int res = -1;
        while(l <= r) {
            m = l+(r-l)/2;
            if(nums[m] >= target) {
                res = m;
                r=m-1;
            } else if(nums[m] < target) {
                l = m+1;
            }
        }
        if(l == nums.size()) return l;
        if(r == -1) return 0;
        return res;
    }
};
// 0 1 2 3 4
// 1 3 5 7 9

// 0: 0
// 10: 5
// 6: 3
// a....b.....c
