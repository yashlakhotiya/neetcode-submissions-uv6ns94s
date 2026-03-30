struct Node {
    int key, val;
    Node* prev, *next;
    Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cap;
    Node *ldum, *rdum;
    unordered_map<int,Node*> mp;

    void markUsed(Node *node) {
        if(node->next && node->prev) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        rdum->prev->next = node;
        node->next = rdum;
        node->prev=rdum->prev;
        rdum->prev=node;
    }

public:
    LRUCache(int capacity) : cap(capacity), ldum(new Node(0,0)), rdum(new Node(0,0)) {
        ldum->next = rdum; rdum->prev=ldum;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node *node = mp[key];
        markUsed(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            mp[key]->val=value;
            markUsed(mp[key]);
            return;
        }
        if(mp.size() == cap) {
            auto lrunode = ldum->next;
            ldum->next = lrunode->next;
            lrunode->next->prev = ldum;
            mp.erase(lrunode->key);
            delete lrunode;
        }
        mp[key] = new Node(key, value);
        markUsed(mp[key]);
    }
};
