/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        // interleaving approach :

        if (!head) return NULL;

        // first make chain : A->A'->B->B'->.....

        Node* l1 = head;
        while (l1) {
            Node* l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
        }

        // now assigning random pointers :
        l1 = head;
        Node* newhead = head->next;

        while (l1) {
            if (l1->random) l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }

        // now separate out the copied list;
        l1 = head;
        while (l1) {
            Node* l2 = l1->next;
            l1->next = l2->next;

            if (l2->next) l2->next = l2->next->next;

            l1 = l1->next;
        }
        return newhead;
    }
};
