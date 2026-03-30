class MyQueue {
public:
    stack<int> stemp, sprim;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!sprim.empty()){
            stemp.push(sprim.top()); sprim.pop();
        }
        stemp.push(x);
        while(!stemp.empty()) {
            sprim.push(stemp.top()); stemp.pop();
        }
    }
    
    int pop() {
        int x = sprim.top();
        sprim.pop();
        return x;
    }
    
    int peek() {
        return sprim.top();
    }
    
    bool empty() {
        return sprim.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */