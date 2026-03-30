struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode(int inputVal) : val(inputVal) {}
};

class MyHashSet {
    int hash(int input) {
        return input%keyStore.size();
    }
public:
    vector<ListNode*> keyStore;
    MyHashSet() {
        keyStore.resize(10000);
    }
    
    void add(int key) {
        int bucketIndex = hash(key);
        ListNode *curr = keyStore[bucketIndex];
        if(curr == nullptr) {
            keyStore[bucketIndex] = new ListNode(key);
            return;
        }
        ListNode *prev = nullptr;
        while(curr) {
            if(curr->val == key) return;
            prev = curr; curr = curr->next;
        }
        ListNode *newNode = new ListNode(key);
        prev->next = newNode;
        return;
    }
    
    void remove(int key) {
        int bucketIndex = hash(key);
        ListNode *curr = keyStore[bucketIndex];
        if(curr == nullptr) return;
        if(curr->val == key) {
            keyStore[bucketIndex] = curr->next;
            curr->next = nullptr;
            return;
        }
        ListNode *prev = nullptr;
        while(curr) {
            if(curr->val == key) break;
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode *currNext = curr->next;
        prev->next = currNext;
        curr->next = nullptr;
        return;
    }
    
    bool contains(int key) {
        int bucketIndex = hash(key);
        ListNode *curr = keyStore[bucketIndex];
        if(!curr) return false;
        while(curr) {
            if(curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */