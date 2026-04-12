class Solution {
public:
    int climb(int i, vector<int> &cache) {
        if(cache[i] != -1) return cache[i];
        return cache[i] = climb(i-1, cache) + climb(i-2, cache);
    }
    int climbStairs(int n) {
        vector<int> cache(n+1, -1);
        cache[0] = cache[1] = 1;
        return climb(n, cache);
    }
};
