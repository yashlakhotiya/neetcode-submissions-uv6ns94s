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
public:
    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        auto curr=head, next=head;
        ListNode *prev=nullptr;
        for(int i=0; i<n-1; i++) {
            next = next->next;
        }
        while(next->next) {
            prev=curr;
            curr = curr->next;
            next = next->next;
        }
        if(!prev) return curr->next;
        prev->next = curr->next;
        curr->next=nullptr;
        return head;
    }
};
