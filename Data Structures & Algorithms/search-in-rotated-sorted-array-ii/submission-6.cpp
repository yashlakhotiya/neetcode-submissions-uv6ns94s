class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l=0, r=arr.size()-1, m=0;
        while(l <= r) {
            m = l+(r-l)/2;
            if(arr[m] == target) return true;
            else {
                if(arr[l] == arr[m]) l++;
                else if(arr[l] <= arr[m]) {
                    if(target >= arr[l] && target < arr[m]) r=m-1;
                    else l=m+1;
                } else if (arr[m] <= arr[r]){
                    if(target > arr[m] && target <= arr[r]) l=m+1;
                    else r=m-1;
                }
            }
        }
        return false;
    }
};