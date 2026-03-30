class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size()-1;
        int boatCount = 0;
        while(l <= r) {
            if(l == r) return ++boatCount;
            if(arr[r]+arr[l] > limit) {
                r--;
                boatCount++;
            } else if(arr[l] + arr[r] <= limit) {
                l++;
                r--;
                boatCount++;
            }
        }
        return boatCount;
    }
};