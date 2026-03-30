class Solution {
public:
    int binSearch(vector<int>& nums, int k) {
        int l=0, r=nums.size(), m = l+(r-l)/2;
        while(l <= r) {
            m = l+(r-l)/2;
            if(k == nums[m]) return m;
            else if(k < nums[m]) r--;
            else l++;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++) {
            int j = binSearch(numbers, target-numbers[i]);
            if(j != -1) return {i+1, j+1};
        }
        return {1,1};
    }
};
