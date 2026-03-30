/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        return clone(head, mp);
    }

    Node* clone(Node* head, unordered_map<Node*,Node*> &mp) {
        if(!head) return nullptr;
        Node *curr = new Node(head->val);
        mp[head] = curr;
        curr->next = clone(head->next, mp);
        curr->random = mp[head->random];
        return curr;
    }
};
