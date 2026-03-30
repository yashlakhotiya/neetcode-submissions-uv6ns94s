class LFUCache {
    unordered_map<int,list<pair<int,int>>::iterator> valmp;
    unordered_map<int,int> freqmp;
    unordered_map<int,list<pair<int,int>>> lrump;
    int cap;
    int lfufreq;
public:
    LFUCache(int capacity) : cap(capacity), lfufreq(0) {
        
    }
    
    int get(int key) {
        if(!valmp.count(key)) return -1;
        auto it = valmp[key];
        int val = it->second;
        int prevfreq = freqmp[key];
        freqmp[key]++;
        lrump[prevfreq].erase(it);
        if(lfufreq == prevfreq && lrump[prevfreq].empty()) lfufreq=freqmp[key];
        lrump[freqmp[key]].push_back({key, val});
        valmp[key] = prev(lrump[freqmp[key]].end());
        return val;
    }
    
    void put(int key, int value) {
        if(valmp.count(key)) {
            auto it = valmp[key];
            int prevfreq = freqmp[key];
            freqmp[key]++;
            lrump[prevfreq].erase(it);
            if(lfufreq == prevfreq && lrump[prevfreq].empty()) lfufreq=freqmp[key];
            lrump[freqmp[key]].push_back({key,value});
            valmp[key] = prev(lrump[freqmp[key]].end());
            return;
        }
        if(valmp.size() == cap) {
            auto deletionnode = lrump[lfufreq].begin();
            valmp.erase(deletionnode->first);
            int prevfreq = freqmp[deletionnode->first];
            freqmp.erase(deletionnode->first);
            lrump[prevfreq].erase(deletionnode);
        }
        freqmp[key]++;
        lrump[freqmp[key]].push_back({key,value});
        valmp[key] = prev(lrump[freqmp[key]].end());
        lfufreq=1;
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */