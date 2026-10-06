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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // brute force approach :

        vector<int> vec;

        for (ListNode* head : lists) {
            for (ListNode* node = head; node; node = node->next) {
                vec.push_back(node->val);
            }
        }

        // sort
        sort(vec.begin(), vec.end());

        // rebuild the linked list :

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int v : vec) {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
        return dummy.next;
    }
};
