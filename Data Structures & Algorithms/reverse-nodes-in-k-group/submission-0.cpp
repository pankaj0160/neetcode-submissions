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
        ListNode* dummy = new ListNode(0, head);
        ListNode* group_prev = dummy;

        while (true) {
            ListNode* kth = getKth(group_prev, k);
            if (!kth) break;
            ListNode* group_next = kth->next;  // first node after the current group
            ListNode* prev = group_next;
            ListNode* curr = group_prev->next;

            // reverse the current group
            while (curr != group_next) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            // now group prev is start of reversed group(kth node)
            ListNode* tmp = group_prev->next;
            group_prev->next = kth;
            group_prev = tmp;
        }
        return dummy->next;
    }

   private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
