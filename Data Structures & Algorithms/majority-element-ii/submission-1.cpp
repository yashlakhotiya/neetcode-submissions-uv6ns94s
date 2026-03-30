class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = nums[0];
        int cand2 = nums[1];
        int cand1Balance = 0;
        int cand2Balance = 0;
        for(int i=0; i<nums.size(); i++) {
            if(cand1Balance == 0) {
                cand1 = nums[i];
                cand1Balance++;
            }
            else if(nums[i] != cand1 && cand2Balance == 0){
                cand2 = nums[i];
                cand2Balance++;
            } else {
                if(nums[i] == cand1) cand1Balance++;
                else if(nums[i] == cand2) cand2Balance++;
                else {
                    if(cand1Balance != 0 && cand2Balance != 0){
                        cand1Balance--;
                        cand2Balance--;
                    }
                } 
            }
        }
        int cand1Freq=0, cand2Freq=0;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == cand1) cand1Freq++;
            else if(nums[i] == cand2) cand2Freq++;
        }
        if(cand1Freq > nums.size()/3) res.push_back(cand1);
        if(cand2Freq > nums.size()/3) res.push_back(cand2);

        return res;
    }
};