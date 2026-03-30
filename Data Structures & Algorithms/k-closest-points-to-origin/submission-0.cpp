struct cmp {
    bool operator()(vector<int> &a, vector<int> &b) {
        int d1 = a[0]*a[0]+a[1]*a[1];
        int d2 = b[0]*b[0]+b[1]*b[1];
        return d1 < d2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto p: points) {
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top()); pq.pop();
        }
        return res;
    }
};
