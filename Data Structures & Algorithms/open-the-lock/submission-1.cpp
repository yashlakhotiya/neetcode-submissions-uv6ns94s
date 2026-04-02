class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        string start = "0000";
        if(deadset.count(start)) return -1;
        queue<pair<string, int>> q; q.push({start, 0});
        deadset.insert(start);
        while(!q.empty()) {
            auto [cur, dist] = q.front(); q.pop();
            if(cur == target) return dist;
            for(int i=0; i<cur.size(); i++) {
                string next = cur;
                next[i] = (next[i]-'0'+1)%10 +'0';
                if(!deadset.count(next)) {
                    q.push({next, dist+1});
                    deadset.insert(next);
                }
                next = cur;
                next[i] = (next[i]-'0'-1+10)%10+'0';
                if(!deadset.count(next)) {
                    q.push({next, dist+1});
                    deadset.insert(next);
                }
            }
        }
        return -1;
    }
};