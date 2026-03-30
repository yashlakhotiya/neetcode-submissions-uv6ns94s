class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue; // if we already found triplets with first number == x, then you can skip all indexes i's where nums[i] = x bcoz they all will lead to same triplets starting with first number = x
            int l=i+1, r=nums.size()-1;
            while(l < r) {
                if(nums[i]+nums[l]+nums[r] > 0) r--;
                else if(nums[i]+nums[l]+nums[r] < 0) l++;
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(l < r && nums[l] == nums[l-1]) l++; // if we already found triplets with second number == x, then you can skip all indexes l's where nums[l] = x bcoz they all will lead to same triplets with second number = x
                }
            }
        }
        return res;
    }
};
//     i  l     r
// -4 -1 -1 0 1 2
