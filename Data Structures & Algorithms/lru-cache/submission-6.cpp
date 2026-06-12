struct ListNode {
    ListNode *prev, *next;
    int key, val;

    ListNode(int key, int val): key(key), val(val) {}
};

class LRUCache {
    map<int,ListNode*> cache;
    ListNode *head, *tail;
    int cap;
    private:
        void addToFront(ListNode *node) {
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
        }
        void deleteNode(ListNode *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    public:
        LRUCache(int capacity) : cap(capacity){
            head = new ListNode(-1, -1);
            tail = new ListNode(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) {
            if(!cache.count(key)) return -1;
            auto node = cache[key];
            deleteNode(node);
            addToFront(node);
            return node->val;
        }
        
        void put(int key, int value) {
            if(cache.count(key)) {
                auto node = cache[key];
                deleteNode(node);
            }
            auto newnode = new ListNode(key, value);
            addToFront(newnode);
            cache[key] = newnode;
            if(cache.size() > cap) {
                auto lrunode = tail->prev;
                deleteNode(lrunode);
                cache.erase(lrunode->key);
            }
        }
};
