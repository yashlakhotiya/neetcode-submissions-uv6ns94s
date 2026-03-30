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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0;
        ListNode *c1=l1, *c2=l2;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while(c1 && c2) {
            int sum = c1->val+c2->val+carry;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            curr->next = node;
            curr = curr->next;
            c1 = c1->next; c2 = c2->next;
        }
        while(c1) {
            int sum = carry+c1->val;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            curr->next = node;
            curr = curr->next;
            c1 = c1->next;
        }

        while(c2) {
            int sum = carry+c2->val;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            curr->next = node;
            curr = curr->next;
            c2 = c2->next;
        }
        if(carry) {
            ListNode *node = new ListNode(carry);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};
