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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *fast=head, *slow=head;
        while(fast && fast->next) {
            slow = slow->next; fast = fast->next->next;
        }
        
        // slow->next points to start of list to be reversed
        ListNode *prev=nullptr, *curr=slow->next;
        slow->next = nullptr;
        while(curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // prev now points to head of reversed list
        ListNode *l1 = head, *l2=prev;
        while(l2) {
            ListNode *l1tmp = l1->next;
            ListNode *l2tmp = l2->next;
            l1->next = l2;
            l2->next = l1tmp;
            l1=l1tmp;
            l2=l2tmp;
        }
    }
};
