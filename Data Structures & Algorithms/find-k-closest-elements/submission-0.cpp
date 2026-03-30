class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int mini = INT_MAX;
        vector<int> res(k,0);
        int l=0, wsum=0, wsize=0, abssum;
        for(int r=0; r<arr.size(); r++) {
            wsum += abs(arr[r]-x);
            if(r-l+1 == k) {
                if(wsum < mini) {
                    mini = wsum;
                    int j=0;
                    for(int i=l; i<=r; i++) res[j++]=arr[i];
                }
            } else if(r-l+1 > k) {
                wsum -= abs(arr[l]-x);
                l++;
                if(wsum < mini) {
                    mini = wsum;
                    int j=0;
                    for(int i=l; i<=r; i++) res[j++]=arr[i];
                }
            }
        } 
        return res;
    }
};