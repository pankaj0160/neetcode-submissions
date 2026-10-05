
class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
   private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;   // dummy : least recently used node near the left side
    Node* right;  // dummy : most recently used node near the right side

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {  // insert node just before right
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

   public:
    LRUCache(int capacity) {  // initialized the LRU cache of size capacity
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newnode = new Node(key, value);
        cache[key] = newnode;
        insert(newnode);

        if (cache.size() > cap) {
            Node* lru = left->next;  // least recently used node delete
            remove(lru);             // from liked list
            cache.erase(lru->key);   // from cache
            delete (lru);
        }
    }
};
