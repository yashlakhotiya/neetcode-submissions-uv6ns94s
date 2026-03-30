class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet;
        for(int num : nums) {
            numSet.insert(num);
        }
        int maxLongestLength = 0;
        for(int num : nums) {
            if(!numSet.count(num-1)) {
                int tempNum = num;
                int longest = 0;
                while(numSet.count(tempNum)) {
                    longest++;
                    tempNum++;
                }
                if(longest > maxLongestLength) maxLongestLength = longest;
            }
        }
        return maxLongestLength;
    }
};