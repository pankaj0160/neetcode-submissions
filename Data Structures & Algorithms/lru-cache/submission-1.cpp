class LRUCache {
    // Doubly-linked list node to store a key-value pair
    class Node {
    public:
        int key;    // unique identifier
        int val;    // associated value
        Node* prev; // pointer to previous node in the list
        Node* next; // pointer to next node in the list

        // Constructor: initialize with key and value, nullify pointers
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

private:
    int capacity;                          // max number of entries allowed
    unordered_map<int, Node*> cache;       // maps key -> Node* for O(1) lookup
    Node* left;                            // dummy head: represents LRU end
    Node* right;                           // dummy tail: represents MRU end

    // Remove a node from its current position in the doubly-linked list
    void remove(Node* node) {
        Node* prevNode = node->prev;       // node immediately before
        Node* nextNode = node->next;       // node immediately after
        prevNode->next = nextNode;         // bypass the removed node
        nextNode->prev = prevNode;
    }

    // Insert a node at the right end (just before the MRU dummy tail)
    // This marks the node as "most recently used"
    void insert(Node* node) {
        Node* prevNode = right->prev;      // current MRU node
        prevNode->next = node;             // link MRU -> new node
        node->prev = prevNode;             // link new -> MRU
        node->next = right;                // link new -> dummy tail
        right->prev = node;                // update dummy tail's prev
    }

public:
    // Constructor: initialize cache with given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;

        // Create two dummy nodes to simplify edge cases:
        // - left dummy marks the LRU end (oldest)
        // - right dummy marks the MRU end (newest)
        left  = new Node(0, 0);
        right = new Node(0, 0);

        // Connect them: left <-> right
        left->next  = right;
        right->prev = left;
    }

    // Retrieve a value by key
    // If found, move the node to MRU position and return its value
    // If not found, return -1
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];       // found in map
            remove(node);                  // detach from current position
            insert(node);                  // re-insert at MRU end
            return node->val;              // return the value
        }
        return -1;                         // key does not exist
    }

    // Insert or update a key-value pair
    // If cache is full, evict the LRU (least recently used) entry first
    void put(int key, int value) {
        // If key already exists, remove the old node from the list
        if (cache.find(key) != cache.end()) {
            Node* existingNode = cache[key];
            remove(existingNode);
            delete existingNode;           // free memory
        }

        // Create a new node and add it to the map
        Node* newNode = new Node(key, value);
        cache[key] = newNode;

        // Insert at MRU position
        insert(newNode);

        // If cache exceeds capacity, remove the LRU node (right after left dummy)
        if (cache.size() > capacity) {
            Node* lruNode = left->next;    // the node right after LRU dummy
            remove(lruNode);               // detach from list
            cache.erase(lruNode->key);     // remove from map
            delete lruNode;                // free memory
        }
    }
};