class Solution {
    int getArea(vector<int>& heights, int i, int j) {
        return min(heights[i], heights[j])*abs(j-i);
    }
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int maxi = getArea(heights, l, r);
        while(l < r) {
            int area = getArea(heights, l, r);
            maxi = max(area, maxi);
            if(heights[l] < heights[r]) l++;
            else if(heights[l] > heights[r]) r--;
            else l++;
        }
        return maxi;
    }
};
