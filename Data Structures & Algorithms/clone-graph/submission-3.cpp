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
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        mp[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            auto n = q.front(); q.pop();
            for(Node *neighbornode: n->neighbors) {
                if(!mp.count(neighbornode)) {
                    Node *copyn= new Node(neighbornode->val);
                    mp[neighbornode] = copyn;
                    q.push(neighbornode);
                }
                mp[n]->neighbors.push_back(mp[neighbornode]);
            }
        }
        return mp[node];
    }
};
