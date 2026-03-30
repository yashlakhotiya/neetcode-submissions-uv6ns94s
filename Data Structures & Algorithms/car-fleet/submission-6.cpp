class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr(position.size());
        for(int i=0; i<position.size(); i++) {
            arr[i] = {position[i], speed[i]};
        }
        sort(arr.begin(), arr.end());
        stack<float> s;
        for(int i=arr.size()-1; i>=0; i--) {
            if(!s.empty() && getTime(arr, target, i) <= s.top()) {
                continue;
            } else {
                s.push(getTime(arr, target, i));
            }
        }
        return s.size();
    }

    float getTime(vector<pair<int,int>> &arr, int target, int i) {
        return float(target-arr[i].first)/arr[i].second;
    }
};
