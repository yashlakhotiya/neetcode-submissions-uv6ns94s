class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         deque<int> q;
         vector<int> res;
         int l=0;
         for(int r=0; r<nums.size(); r++) {
            while(!q.empty() && q.front() <= r-k) {
                q.pop_front();
            }
            while(!q.empty() && nums[r] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(r);
            if(r >= k-1) res.push_back(nums[q.front()]);
         }
         return res;
    }
};
