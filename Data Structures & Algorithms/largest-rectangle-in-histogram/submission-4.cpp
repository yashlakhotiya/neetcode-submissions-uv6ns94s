class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<int> s;
        for(int i=0; i<=heights.size(); i++) {
            int nse = heights.size(), pse=-1;
            int h = (i == heights.size() ? 0 : heights[i]);
            while(!s.empty() && h < heights[s.top()]) {
                int element = s.top(); s.pop();
                nse = i;
                pse = s.empty()?-1:s.top();
                maxi=max(maxi, heights[element] * (nse-pse-1));
            }
            s.push(i);
        }
        return maxi;
    }
};

//      7, 1, 7, 2, 2, 4
// pse -1,-1, 1, 
// nse  1,    2, 
// cur  2
// s:   1, 2







