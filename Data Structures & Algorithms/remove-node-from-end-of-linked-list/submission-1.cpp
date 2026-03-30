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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        int len=0;
        auto curr = head;
        while(curr) {
            len++; curr = curr->next;
        }
        int startPos=len-n;
        curr=head;
        if(startPos == 0) {
            auto next = curr->next; curr->next=nullptr;
            return next;
        }
        int k=0;
        ListNode *prev=nullptr;
        while(curr->next && k != startPos) {
            k++;
            prev=curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next=nullptr;
        return head;
    }
};
