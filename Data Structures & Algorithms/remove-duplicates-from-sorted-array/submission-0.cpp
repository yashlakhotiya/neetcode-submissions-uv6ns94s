class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, m = 1;
        while(m < nums.size()) {
            while(m < nums.size() && nums[m] == nums[l]) {
                m++;
            }
            if(m >= nums.size()) return l+1;
            l++;
            if(m < nums.size()) {
                nums[l] = nums[m];
            }
            m++;
        }
        return l+1;
    }
};
//   l             m
// 2,30,10,10,30,30