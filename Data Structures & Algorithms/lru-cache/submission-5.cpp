struct ListNode {
    int key, value;
    ListNode *prev, *next;
    ListNode(int key, int val): key(key), value(val) {}
};

class LRUCache {
    int cap;
    unordered_map<int,ListNode*> cache;
    ListNode *head, *tail;
    private:
    void remove(ListNode *node) {
        auto prev = node->prev;
        auto next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(ListNode *node) {
        auto lastnode = tail->prev;
        lastnode->next = node;
        node->prev = lastnode;
        node->next = tail;
        tail->prev = node;
    }
    public:
    LRUCache(int cap) : cap(cap) {
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void put(int key, int value) {
        if(cache.count(key)) {
            remove(cache[key]);
        }
        auto newnode = new ListNode(key,value);
        cache[key] = newnode;
        insert(newnode);
        if(cache.size() > cap) {
            auto lrunode = head->next;
            remove(lrunode);
            cache.erase(lrunode->key);
            delete lrunode;
        }
    }

    int get(int key) {
        if(cache.count(key) == 0) return -1;
        auto node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
};