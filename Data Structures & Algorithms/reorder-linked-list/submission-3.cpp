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
        // new approach :
        // find middle element : using slow and fast pointer
        // reverse the second half  : second = slow->next
        // merge the second half and the reversed second half alternatively

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the second half
        ListNode* prev = NULL;
        ListNode* second = slow->next;
        slow->next = NULL;  // split into two lists

        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        ListNode* first = head;

        // merge :
        while (prev && first) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = prev->next;

            first->next = prev;
            prev->next = temp1;
            first = temp1;
            prev = temp2;
        }
        return;
    }
};
