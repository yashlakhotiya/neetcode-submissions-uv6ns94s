class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = accumulate(gas.begin(), gas.end(), 0);
        int totalcost = accumulate(cost.begin(), cost.end(), 0);
        if(totalgas < totalcost) return -1;
        int n = gas.size();
        int tank = 0;
        int res = 0;
        for(int i=0; i<n; i++) {
            tank += gas[i]-cost[i];
            if(tank < 0) {
                tank = 0;
                res = i+1;
            }
        }
        return res;
    }
};
