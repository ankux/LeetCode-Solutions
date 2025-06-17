class LRUCache {
public:
    class Node {
        public:
            int key, val;
            Node* next;
            Node* prev;

            Node(int k, int v) {
                key = k;
                val = v;
                next = prev = NULL;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNode = head->next;

        head->next = newNode;
        oldNode->prev = newNode;

        newNode->next = oldNode;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode) {
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    
    int get(int key) {
        // if key does not exists
        if(mp.find(key) == mp.end()) return -1;

        Node* ansNode = mp[key];
        int ans = ansNode->val;

        mp.erase(ansNode->key);
        deleteNode(ansNode);

        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        // if key exist already in the map
        if(mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
        }

        // if limit/capacity is reached, delete LRU (the last node)
        if(mp.size() == limit) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */