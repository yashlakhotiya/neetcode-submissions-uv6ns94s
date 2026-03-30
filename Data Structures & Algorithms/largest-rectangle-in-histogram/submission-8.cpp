class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<int> s;
        for(int i=0; i<heights.size(); i++) {
            int pse=-1, nse=heights.size();
            while(!s.empty() && heights[i] < heights[s.top()]) {
                int element = s.top(); s.pop();
                nse = i; pse = s.empty()?-1:s.top();
                maxi = max(maxi, heights[element]*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()) {
            int element = s.top(); s.pop();
            int nse = heights.size(), pse = s.empty()?-1:s.top();
            maxi = max(maxi, heights[element]*(nse-pse-1));
        }
        return maxi;
    }
};
