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
        // better approach : two pointer approach (slow and fast pointers)

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // move fast to n step
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // move both untill fast reaches the last node;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // now slow is at the one before the removing node :
        slow->next = slow->next->next;
        return dummy->next;
    }
};
