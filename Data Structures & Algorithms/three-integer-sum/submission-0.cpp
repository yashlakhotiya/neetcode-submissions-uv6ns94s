class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) break;
            int l=i+1, r=nums.size()-1;
            while(l < r) {
                if(nums[i]+nums[l]+nums[r] > 0) r--;
                else if(nums[i]+nums[l]+nums[r] < 0) l++;
                else{
                    vector<int> tempRes = vector<int>{nums[i], nums[l], nums[r]};
                    sort(tempRes.begin(), tempRes.end());
                    if(s.count(tempRes) == 0) {
                        s.insert(tempRes);
                        res.push_back(tempRes);
                    }
                    l++; r--;
                }
            }
        }
        return res;
    }
};
//     i  l     r
// -4 -1 -1 0 1 2
