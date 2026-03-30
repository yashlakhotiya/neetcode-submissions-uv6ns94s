class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            int contra = target-n;
            if(mp.find(contra) == mp.end()) {
                mp[n] = i;
            } else {
                int j = mp[contra];
                if(i < j) return {i,j};
                else return {j,i};
            }
        }
        return {};
    }
};
