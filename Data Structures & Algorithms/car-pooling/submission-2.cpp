struct cmp {
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.first>b.first;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int curpas=0;
        for(auto v : trips) {
            int pas = v[0], from=v[1], to=v[2];
            while(!pq.empty() && pq.top().first <= from) {
                curpas -= pq.top().second;
                pq.pop();
            }
            curpas += pas;
            if(curpas > capacity) return false;
            pq.push({to, pas});
        }
        return true;
    }
};