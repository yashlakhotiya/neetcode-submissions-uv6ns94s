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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *head = nullptr;
        auto curr = head;
        auto curr1 = list1, curr2 = list2;
        while(curr1 && curr2) {
            if(curr1->val <= curr2->val) {
                auto curnext = curr1->next;
                curr1->next = nullptr;
                if(!curr) {
                    curr=curr1;
                    head = curr;
                }
                else {
                    curr->next = curr1;
                    curr = curr->next;
                }
                curr1 = curnext;
            } else if(curr2->val < curr1->val) {
                auto curnext = curr2->next;
                curr2->next = nullptr;
                if(!curr) {
                    curr=curr2;
                    head = curr;
                }
                else {
                    curr->next = curr2;
                    curr = curr->next;
                }
                curr2 = curnext;
            }
        }
        if(curr1) {
            curr->next = curr1;
        } else if(curr2) {
            curr->next = curr2;
        }
        return head;
    }
};
