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
        // let's try recursive approach

        if (!head->next || !head->next->next) return;

        ListNode* first = head;
        ListNode* last = head;

        while (last->next->next) {
            last = last->next;
        }
        last->next->next = first->next;
        first->next = last->next;
        last->next = NULL;

        reorderList(first->next->next);
    }
};
