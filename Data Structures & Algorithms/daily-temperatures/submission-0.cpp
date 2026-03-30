class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size(),0);
        for(int i=0; i<temperatures.size(); i++) {
            if(s.empty()) s.push(i);
            else {
                while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                    res[s.top()] = i-s.top(); s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};
