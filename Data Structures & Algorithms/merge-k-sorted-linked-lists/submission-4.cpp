/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x, next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // ─── EDGE CASE ───────────────────────────────────────────────
        // If there are no lists at all, return null immediately.
        if (lists.empty()) return nullptr;

        // ─── STEP 1: DEFINE THE COMPARATOR ───────────────────────────
        // C++ priority_queue is a MAX-HEAP by default.
        // To turn it into a MIN-HEAP, we reverse the comparison:
        //   "a has LOWER priority than b" when a->val > b->val
        // This ensures the smallest value sits on TOP of the heap.
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // ─── STEP 2: INITIALIZE THE MIN-HEAP ─────────────────────────
        // Template parameters explained:
        //   ListNode*          → what we store (pointers to nodes)
        //   vector<ListNode*>  → underlying container (required by std)
        //   decltype(cmp)      → type of our custom comparator
        // We pass 'cmp' to the constructor because it's a lambda
        // (non-static state needs to be provided at runtime).
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minheap(cmp);

        // ─── STEP 3: SEED THE HEAP WITH HEADS OF ALL NON-EMPTY LISTS ─
        // We only push the FIRST node of each list.
        // Why? Because each list is already sorted internally,
        // so the head is guaranteed to be its current minimum.
        // Skipping nulls prevents crashes when accessing ->val later.
        for (ListNode* list : lists) {
            if (list) {              // Only push if the list is not empty
                minheap.push(list);  // O(log k) per insertion
            }
        }

        // ─── STEP 4: BUILD THE RESULT LIST ───────────────────────────
        // A dummy node simplifies edge cases (no special handling needed
        // for the very first node we attach). It lives on the stack,
        // so it gets cleaned up automatically — no memory leak.
        ListNode dummy(0);
        ListNode* cur = &dummy;      // 'cur' always points to the tail of result

        // ─── STEP 5: EXTRACT-MIN AND ADVANCE ─────────────────────────
        // Invariant: the heap always contains exactly one candidate
        // (the current front) from each list that still has nodes left.
        // Therefore heap.top() is ALWAYS the global smallest remaining value.
        while (!minheap.empty()) {

            // Extract the globally smallest node among all current heads.
            ListNode* node = minheap.top();
            minheap.pop();           // Remove it from the heap

            // Append this node to our merged result list.
            cur->next = node;        // Link previous tail to this node
            cur = cur->next;         // Advance tail pointer

            // Advance within the source list and feed the next candidate
            // back into the heap. If node->next is null, that list is
            // exhausted, so we simply don't push anything (heap shrinks).
            if (node->next) {
                minheap.push(node->next);
            }
        }

        // ─── STEP 6: RETURN ──────────────────────────────────────────
        // dummy.next is the real head of the merged list
        // (dummy itself was just a placeholder with value 0).
        return dummy.next;
    }
};