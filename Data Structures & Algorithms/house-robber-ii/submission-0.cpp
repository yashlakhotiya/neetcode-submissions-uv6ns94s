class Solution {
public:
    int rob(vector<int>& nums, bool pickfirstele) {
        int start = 1, end = nums.size();
        if(pickfirstele) {
            start = 0, end = nums.size()-1;
        }
        int n1 = 0, n2 = 0;
        for(int i=end-1; i>=start; i--) {
            int temp = max(n1, nums[i]+n2);
            n2 = n1; n1 = temp;
        }
        return n1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(rob(nums, false), rob(nums, true));
    }
};
