class LRUCache {
public:
    list<int> dll;
    // map<key, pair<address_of_the_node, value_of_key>>
    map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeMRU(int key) {
        // firstly, delete the key from the DLL
        dll.erase(mp[key].first);

        // secondly, push the key to the front of the DLL
        // since, we are keeping MRU elements at the front
        dll.push_front(key);

        // lastly, update the address of this key in the map,
        // as the address is been updated for this key
        mp[key].first = dll.begin();        
    }

    int get(int key) {
        // if the key is not present in the map, return -1
        if(mp.find(key) == mp.end()) return -1;

        // if the key is present,
        // first, make it Most Recently Used
        makeMRU(key);

        // then, return the corresponding value of the key from the map
        return mp[key].second;
    }
    
    void put(int key, int value) {
        // if the key is present then, update the value and,
        // make it MRU
        if(mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeMRU(key);
            return;
        }

        if(n == mp.size()) {
            // if the cache is full, we will remove the last (or LRU) key node
            // from both map and DLL, since it is least recently used, 
            // dll.back() => gives key of the last node 
            mp.erase(dll.back());

            // removing the last (or LRU) node from the DLL
            dll.pop_back();
        }

        // we will then push the new key into the DLL
        dll.push_front(key);

        // we will also update the map with new key -> <addr, value>
        // dll.begin() => gives the address of the first node
        mp[key] = {dll.begin(), value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */