class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        vector<int> temp(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            temp[(i+k)%nums.size()] = nums[i];
        }
        for(int i=0; i<nums.size(); i++) {
            nums[i] = temp[i];
        }
    }
};