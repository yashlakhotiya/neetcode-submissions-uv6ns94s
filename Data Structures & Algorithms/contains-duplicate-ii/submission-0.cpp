class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0, j=0;
        while(true) {
            if(j == nums.size()) return false;
            if(j-i <= k) {
                if(!mp[nums[j]]) mp[nums[j++]] = 1;
                else return true;
            } else {
                mp.erase(nums[i++]);
            }
        }
        return false;
    }
};

//    1,2,3,4,5,6,1,2,3,1
//   i.     j