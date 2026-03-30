struct Task {
    int idx;
    int etime;
    int ptime;
    Task(int idx, int etime, int ptime) : idx(idx), etime(etime), ptime(ptime) {}
};

struct taskpqcmp {
    bool operator()(Task t1, Task t2) {
        if(t1.ptime == t2.ptime) return t1.idx > t2.idx;
        return t1.ptime > t2.ptime;
    }
};

struct tasklistcmp {
    bool operator()(Task t1, Task t2) {
        return t1.etime < t2.etime;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        if(tasks.empty()) return {};
        vector<Task> tasklist;
        for(int i=0; i<tasks.size(); i++) {
            tasklist.push_back(Task(i, tasks[i][0], tasks[i][1]));
        }
        sort(tasklist.begin(), tasklist.end(), tasklistcmp());
        vector<int> res;
        int time=0;
        priority_queue<Task, vector<Task>, taskpqcmp> pq;
        int i=0;
        while(!pq.empty() || i < tasklist.size()) {
            while(i < tasklist.size() && time >= tasklist[i].etime) {
                pq.push(tasklist[i++]);
            }
            if(pq.empty()) {
                time = tasklist[i].etime;
            } else {
                auto task = pq.top(); pq.pop();
                time+=task.ptime;
                res.push_back(task.idx);
            }
        }
        return res;
    }
};