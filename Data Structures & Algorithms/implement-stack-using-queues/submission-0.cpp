class MyStack {
    queue<int> qprim, qtemp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        qtemp.push(x);
        while(!qprim.empty()) {
            qtemp.push(qprim.front()); qprim.pop();
        }
        swap(qprim, qtemp);
    }
    
    int pop() {
        int x = qprim.front();
        qprim.pop();
        return x;
    }
    
    int top() {
        return qprim.front();
    }
    
    bool empty() {
        return qprim.empty();
    }
};

// ------

// ------
// 4 3 2 1
// ------

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */