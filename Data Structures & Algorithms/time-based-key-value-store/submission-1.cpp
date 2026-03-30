class TimeMap {
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        auto &values = mp[key];
        int l=0, r=values.size()-1, m=0;
        int res = -1;
        while(l <= r) {
            m = l+(r-l)/2;
            if(values[m].first <= timestamp) {
                res = m;
                l=m+1;
            } else {
                r=m-1;
            }
        }
        if(res == -1) return "";
        return values[res].second;
    }
};
