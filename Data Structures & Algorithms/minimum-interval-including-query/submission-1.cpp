class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> sortedqueries = queries;
        sort(sortedqueries.begin(), sortedqueries.end());
        unordered_map<int, int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int i=0;
        for(int q: sortedqueries) {
            while(i < intervals.size() && intervals[i][0] <= q) {
                int is = intervals[i][0], ie = intervals[i][1];
                pq.push({ie-is+1, ie});
                i++;
            }
            while(!pq.empty() && pq.top().second < q) pq.pop();
            if(pq.empty()) mp[q] = -1;
            else mp[q] = pq.top().first;
        }
        vector<int> res;
        for(int q: queries) {
            res.push_back(mp[q]);
        }
        return res;
    }
};
