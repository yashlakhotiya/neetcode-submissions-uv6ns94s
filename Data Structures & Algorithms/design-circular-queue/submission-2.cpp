struct Node {
    int val;
    Node *prev, *next;

    Node(int val) : val(val) {}
};

class MyCircularQueue {
    int size, capacity;
    Node *ldum, *rdum;
public:
    MyCircularQueue(int k) : size(0), capacity(k)
    {
        ldum = new Node(0);
        rdum = new Node(0);
        ldum->next = rdum; rdum->prev = ldum;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        Node *curr = rdum->prev;
        Node *n = new Node(value);
        curr->next = n;
        n->next=rdum;
        rdum->prev = n;
        n->prev=curr;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        Node *nxt = ldum->next->next;
        Node *delnode = ldum->next;
        ldum->next = nxt;
        delnode->prev = nullptr;
        delnode->next=nullptr;
        nxt->prev=ldum;
        delete delnode;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:ldum->next->val;
    }
    
    int Rear() {
        return isEmpty()?-1:rdum->prev->val;
    }
    
    bool isEmpty() {
        return size==0?true:false;
    }
    
    bool isFull() {
        return size==capacity?true:false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */