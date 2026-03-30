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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        auto cur=head; int cnt = 0;
        while(cur && cnt<k) {
            cnt++;
            cur=cur->next;
        }
        if(cnt<k) return head;
        ListNode *prev=nullptr;
        auto ncur=head;
        while(ncur != cur) {
            auto next = ncur->next;
            ncur->next=prev;
            prev=ncur;
            ncur=next;
        }
        head->next = reverseKGroup(ncur, k);
        return prev;
    }
};
