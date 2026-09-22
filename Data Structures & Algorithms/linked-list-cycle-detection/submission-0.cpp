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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;

        while (head) {
            if (s.find(head) != s.end()) return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};
