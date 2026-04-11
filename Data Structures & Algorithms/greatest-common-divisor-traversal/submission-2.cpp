class DS {
    vector<int> parent, size;
    int nocomponents;
    public:
    DS(int n) : nocomponents(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n,1);
    }

    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i]=find(parent[i]);
    }

    bool unn(int i, int j) {
        int p1 = find(i), p2 = find(j);
        if(p1==p2) return false;
        if(size[p1]<size[p2]) swap(p1, p2);
        parent[p2] = p1;
        size[p1] += size[p2];
        nocomponents--;
        return true;
    }

    int getnocomponents() {
        return nocomponents;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DS ds(n);
        unordered_map<int,int> adj;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            for(int factor=2; factor<=num; factor++) {
                if(num%factor == 0) {
                    if(adj.count(factor) == 0) {
                        adj[factor] = i;
                    }
                    ds.unn(adj[factor], i);
                    while(num%factor == 0) {
                        num /= factor;
                    }
                }
            }
        }
        return ds.getnocomponents()==1;
    }
};