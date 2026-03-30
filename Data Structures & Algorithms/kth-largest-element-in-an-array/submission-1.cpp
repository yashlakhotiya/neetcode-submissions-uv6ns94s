class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0, r=nums.size()-1, pivot=-1;
        k = nums.size()-k;
        while(pivot != k) {
            pivot = partition(nums, l, r);
            if(pivot < k)  l = pivot+1;
            else if(pivot > k) r = pivot-1;
            else break;
        }
        return nums[pivot];
    }

    int partition(vector<int>& nums, int l, int r) {
        int pind = r, pval = nums[r];
        int i=l;
        for(int j=l; j<r; j++) {
            if(nums[j] < pval) swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }
};
