struct KvPair {
    int key;
    int val;
    KvPair(int key, int val) : key(key), val(val) {}
};

class MyHashMap {
public:
    vector<KvPair*> mapStore;
    MyHashMap() {
        mapStore.resize(1000001);
    }
    
    void put(int key, int value) {
        mapStore[key] = new KvPair(key, value);
    }
    
    int get(int key) {
        if(mapStore[key]) return mapStore[key]->val;
        return -1;
    }
    
    void remove(int key) {
        mapStore[key] = nullptr;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */