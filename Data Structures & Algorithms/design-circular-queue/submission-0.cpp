class MyCircularQueue {
    vector<int> q;
    int front, rear, size, capacity;
public:
    MyCircularQueue(int k) : q(k), capacity(k), size(0), front(0), rear(-1) {
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear+1)%capacity;
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:q[front];
    }
    
    int Rear() {
        return isEmpty()?-1:q[rear];
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