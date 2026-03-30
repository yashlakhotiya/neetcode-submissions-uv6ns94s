class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqmp;
        for(char c: tasks) freqmp[c]++;
        priority_queue<pair<int,char>> pq;
        for(pair<int,char> p: freqmp) {
            pq.push({p.second, p.first});
        }
        queue<pair<pair<int,char>, int>> q;
        int time=0;
        int cnt = tasks.size();
        
        while(cnt > 0) {
            time++;
            if(!pq.empty()) {
                auto top = pq.top(); pq.pop();
                top.first--;
                cnt--;
                if(top.first) q.push({top, time+n});
            }
            if(q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
