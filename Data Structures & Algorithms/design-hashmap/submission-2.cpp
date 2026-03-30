class ListNode {
    int key;
    int val;
    ListNode* next = nullptr;

    void insertKvPair(int key, int val) {
        ListNode* curr = this->next;
        ListNode* prev = this;
        while(curr) {
            if(curr->key == key){
                curr->val = val;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new ListNode(key, val);
    }

    int getVal(int key) {
        ListNode* curr = this->next;
        while(curr) {
            if(curr->key == key) return curr->val;
            curr = curr->next;
        }
        return -1;
    }

    bool removeKey(int key) {
        ListNode* prev = this;
        ListNode* curr = this->next;
        while(curr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }
        if(!curr) return false;
        ListNode* temp = curr;
        curr = curr->next;
        prev->next = curr;
        delete temp;
        return true;
    }

    public:
    ListNode(int key, int val) : key(key), val(val) {}
    ~ListNode() {
        delete next;
    }

    void insert(int key, int val) {
        insertKvPair(key, val);
    }

    int search(int key) {
        return getVal(key);
    }

    void remove(int key) {
        removeKey(key);
    }
};

class MyHashMap {
    const int size = 10000;
    vector<ListNode*> container;
    int hash(int key) {
        return key%size;
    }
public:
    MyHashMap() {
        container.resize(size);
        for(int i=0; i<size; i++) {
            container[i] = new ListNode(-1, -1);
        }
    }
    ~MyHashMap() {
        for(auto node : container) {
            delete node;
        }
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        container[idx]->insert(key, value);
    }
    
    int get(int key) {
        int idx = hash(key);
        return container[idx]->search(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        container[idx]->remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */