class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> unique;
        for(int i : nums){
            if (unique.find(i) != unique.end()) {
                return true;
            } else {
                unique.insert(i);
            }
        }
        return false;
    }
};