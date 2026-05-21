/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node, unordered_map<Node*, Node*> &cache) {
        if(cache.count(node) != 0) return cache[node];
        Node* newnode = new Node(node->val);
        cache[node] = newnode;
        for(auto neigh: node->neighbors) {
            newnode->neighbors.push_back(clone(neigh, cache));
        }
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cache;
        cache[NULL] = NULL;
        return clone(node, cache);
    }
};
