class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1, m=1, n = nums.size();
        while(m < n) {
            while(nums[m] == nums[m-1]) {
                m++;
            }
            if(m < n) nums[l++] = nums[m++];
        }
        return l;
    }
};