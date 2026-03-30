class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse(heights.size(), -1);
        vector<int> nse(heights.size(), heights.size());
        stack<int> s1, s2;

        for(int i=0; i<heights.size(); i++) {
            while(!s1.empty() && heights[s1.top()] > heights[i]) {
                s1.pop();
            }
            pse[i] = s1.empty()?-1:s1.top();
            s1.push(i);
        }

        for(int i=0; i<heights.size(); i++) {
            while(!s2.empty() && heights[s2.top()] > heights[i]) {
                nse[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }

        int maxi = 0;
        for(int i=0; i<heights.size(); i++) {
            maxi=max(maxi, heights[i] * (nse[i]-pse[i]-1));
        }
        return maxi;
    }
};

//      7, 1, 7, 2, 2, 4
// pse -1,-1, 1, 
// nse  1,    2, 
// cur  2
// s:   1, 2







