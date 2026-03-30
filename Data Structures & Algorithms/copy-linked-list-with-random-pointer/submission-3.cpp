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
        if(!head) return nullptr;
        Node *curr=head;
        while(curr) {
            Node *n = new Node(curr->val);
            Node *next = curr->next;
            curr->next = n;
            n->next = next;
            curr = next;
        }

        curr=head;
        Node *newhead = curr->next;

        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr=head;
        while(curr) {
            Node *curnxt = curr->next;
            curr->next = curnxt->next;
            if(curnxt->next) {
                curnxt->next = curnxt->next->next;
            }
            curr = curr->next;
        }

        return newhead;
    }
};
