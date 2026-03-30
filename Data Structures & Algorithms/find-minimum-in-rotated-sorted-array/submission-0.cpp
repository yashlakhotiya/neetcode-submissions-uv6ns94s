class Solution {
public:
    int findMin(vector<int> &arr) {
        int l=0, r=arr.size()-1, m=0;
        int mini = arr[0];
        while(l <= r) {
            m = l+(r-l)/2;
            if(arr[l] <= arr[m]) {
                mini=min(mini, arr[l]);
                l=m+1;
            } else if(arr[m] <= arr[r]) {
                mini=min(mini, arr[m]);
                r=m-1;
            }
        }
        return mini;
    }
};