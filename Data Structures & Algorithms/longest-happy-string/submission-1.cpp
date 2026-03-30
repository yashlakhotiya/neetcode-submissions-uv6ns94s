class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        string res = "";
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            char currchar = top.second;
            int currcnt = top.first;
            if(res.size() >= 2 && res[res.size()-1] == currchar && res[res.size()-2] == currchar) {
                if(pq.empty()) return res;
                auto nexttop = pq.top(); pq.pop();
                char nextchar = nexttop.second;
                int nextcnt = nexttop.first;
                nextcnt--;
                res += nextchar;
                if(nextcnt) pq.push({nextcnt, nextchar});
            } else {
                currcnt--;
                res += currchar;
            }
            if(currcnt) pq.push({currcnt, currchar});
        }
        return res;
    } 
};