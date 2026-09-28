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
    unordered_map<Node*, Node*> mp;

   public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // if multiple nodes points to same as random pointer then it will create duplicacy
        if (mp.count(head)) return mp[head];

        Node* copy = new Node(head->val);
        mp[head] = copy;
        copy->next = copyRandomList(head->next);      // creates the next chain
        copy->random = copyRandomList(head->random);  // creates random targets too

        return copy;
    }
};
