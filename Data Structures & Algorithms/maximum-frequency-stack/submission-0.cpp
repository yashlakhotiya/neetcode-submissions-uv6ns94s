class FreqStack {
    priority_queue<vector<int>> pq;
    unordered_map<int,int> freqmp;
    int index;
public:
    FreqStack() {
        index=0;
    }
    
    void push(int val) {
        freqmp[val]++;
        pq.push({freqmp[val], index++, val});
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        freqmp[top[2]]--;
        return top[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */