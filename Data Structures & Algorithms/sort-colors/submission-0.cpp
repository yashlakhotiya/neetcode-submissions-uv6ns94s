class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size()-1;
        while(l <= r && m <= r) {
            if(nums[m] == 1){
                m++;
            }
            else if(nums[m] == 0) {
                swap(nums, l, m);
                l++; m++;
            } else {
                swap(nums, m , r);
                r--;
            }
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

//   0 0 1 1 1 1 2 0 1 2
//       l       m     r