class LRUCache {
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int cap;
public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto it = mp[key];
        int val = it->second;
        cache.erase(it);
        cache.push_back({key,val});
        mp[key] = prev(cache.end());
        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            auto it = mp[key];
            cache.erase(it);
            cache.push_back({key,value});
            mp[key] = prev(cache.end());
            return;
        }
        if(mp.size() == cap) {
            auto lru = cache.front();
            auto it = mp[lru.first];
            cache.erase(it);
            mp.erase(lru.first);
        }
        cache.push_back({key,value});
        mp[key] = prev(cache.end());
    }
};
