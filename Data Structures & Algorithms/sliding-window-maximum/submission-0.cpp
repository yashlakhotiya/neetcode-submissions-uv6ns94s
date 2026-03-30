class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1);
        int p=0;
        deque<int> q;
        for(int r=0; r<n; r++) {
            while(!q.empty() && q.front()<r-k+1) q.pop_front();
            while(!q.empty() && nums[r]>=nums[q.back()]) q.pop_back();
            q.push_back(r);
            if(r>=k-1) res[p++]=nums[q.front()];
        }
        return res;
    }
};

// 1,2,1,0,4,2,6
