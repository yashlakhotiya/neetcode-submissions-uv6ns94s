class Solution {
public:
    void dfs(int start, vector<int> adj[], vector<bool> &visited) {
        if(visited[start]) return;
        visited[start] = true;
        for(int n: adj[start]) {
            dfs(n, adj, visited);
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        vector<int> adj[nums.size()];
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(gcd(nums[i], nums[j]) > 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(nums.size(), false);
        dfs(0, adj, visited);
        for(int i=0; i<nums.size(); i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
};