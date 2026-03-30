class Solution {
public: 
    int trap(vector<int>& arr) {
        int l=0, r=arr.size()-1;
        int lmax = arr[l], rmax = arr[r];
        int res = 0;
        while(l <= r) {
            if(lmax < rmax) {
                lmax = max(lmax, arr[l]);
                res += max(0,lmax-arr[l]);
                l++;
            } else {
                rmax = max(rmax, arr[r]);
                res += max(0,rmax-arr[r]);
                r--;
            }
        }
        return res;
    }
};
