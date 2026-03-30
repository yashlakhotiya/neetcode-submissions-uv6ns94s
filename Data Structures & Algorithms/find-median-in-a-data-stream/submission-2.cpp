class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> lefthalf;
    priority_queue<int, vector<int>, greater<int>> righthalf;
    MedianFinder() {
    }
    
    void addNum(int num) {
        lefthalf.push(num);

        righthalf.push(lefthalf.top());
        lefthalf.pop();

        if(righthalf.size()-lefthalf.size() > 1) {
            lefthalf.push(righthalf.top());
            righthalf.pop();
        }
    }
    
    double findMedian() {
        if(lefthalf.size() > righthalf.size()) return lefthalf.top();
        else if(righthalf.size() > lefthalf.size()) return righthalf.top();
        else return (double)(lefthalf.top()+righthalf.top())/2;
    }
};
