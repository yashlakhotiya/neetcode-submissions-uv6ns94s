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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        auto curr = head;
        auto next = head->next;
        int gcd = __gcd(curr->val, next->val);
        ListNode *node = new ListNode(gcd);
        curr->next = node; node->next = insertGreatestCommonDivisors(next);
        return head;
    }
};