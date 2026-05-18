class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r = arr.size()-k, m=0;
        while(l < r) {
            m = l+(r-l)/2;
            if(abs(arr[m]-x) <= abs(arr[m+k]-x)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};