class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, height[i]);
            maxLeft[i] = maxi;
        }
        maxi = 0;
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, height[i]);
            maxRight[i] = maxi;
        }
        int water = 0;
        for(int i=0; i<n; i++) {
            water += min(maxLeft[i], maxRight[i])-height[i];
        }
        return water;
    }
};
