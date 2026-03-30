struct cmp {
    bool operator()(pair<int,char> a, pair<int,char> b) {
        return a.first < b.first;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int maxi = 0;
        for(char c: s) {
            mp[c]++;
            maxi = max(maxi, mp[c]);
        }
        int n = s.size();
        int rem = n-maxi;
        if(rem < maxi-1) return "";
        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;
        
        for(auto p: mp) {
            pq.push({p.second, p.first});
        }
        string res = "";
        while(pq.size() >= 2) {
            auto top1 = pq.top(); pq.pop();
            res += top1.second;
            top1.first--;
            auto top2 = pq.top(); pq.pop();
            res += top2.second;
            top2.first--;
            if(top1.first) pq.push(top1);
            if(top2.first) pq.push(top2);
        }
        while(!pq.empty()) {
            auto top1 = pq.top(); pq.pop();
            res += top1.second;
            top1.first--;
            if(top1.first) pq.push(top1);
        }
        return res;
    }
};