class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, m = 0, n = nums.size();
        while(m < n) {
            nums[l] = nums[m];
            while(nums[l] == nums[m]) {
                m++;
            }
            l++;
        }
        return l;
    }
};
//   l             m
// 2,30,10,10,30,30