/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> minhp;
        for(auto node: lists) {
            if(node) minhp.push(node);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while(!minhp.empty()) {
            auto top = minhp.top(); minhp.pop();
            curr->next = top;
            curr = curr->next;
            if(top->next) minhp.push(top->next);
        }
        return dummy->next;
    }
};
