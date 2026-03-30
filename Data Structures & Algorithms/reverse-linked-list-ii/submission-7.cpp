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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *lprev = &dummy, *l=head;
        for(int i=0; i<left-1; i++) {
            lprev = l;
            l = l->next;
        }
        ListNode *prev = nullptr;
        ListNode *curr = l;
        for(int i=0; i<right-left+1; i++) {
            auto nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        l->next = curr;
        lprev->next = prev;
        return dummy.next;
    }
};