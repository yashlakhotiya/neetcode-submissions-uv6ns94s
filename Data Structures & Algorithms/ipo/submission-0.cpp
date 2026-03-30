struct cmp {
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int cap = w;
        int np = 0;
        vector<pair<int,int>> arr;
        for(int i=0; i<profits.size(); i++) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end(), [](pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        int i = 0;
        while(np < k) {
            while(i < arr.size() && cap >= arr[i].first) {
                pq.push({arr[i].first, arr[i].second});
                i++;
            }
            if(pq.empty()) return cap;
            auto top = pq.top(); pq.pop();
            cap += top.second;
            np++;
        }
        return cap;
    }
};