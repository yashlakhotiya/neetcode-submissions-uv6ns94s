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
        int len = 0;
        auto curr = head;
        while(curr) {
            len++;
            curr = curr->next;
        }
        int k = len-n+1;
        if(k == 1) {
            ListNode *curr = head->next;
            head->next = NULL;
            head = curr;
            return head;
        }
        curr = head;
        ListNode *prev = nullptr;
        int nodePosition=1;
        while(curr->next && nodePosition != k) {
            nodePosition++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        return head;
    }
};
