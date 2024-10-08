class LRUCache {
private:
    // Doubly Linked List to store keys in order of their usage
    list<pair<int, int>> dq; // {key, value}
    // Hashmap for fast access to keys
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;

public:
    // Constructor to initialize cache with a given capacity
    LRUCache(int capacity) { this->capacity = capacity; }

    // Get the value (will always be positive) of the key if the key exists in
    // the cache, otherwise return -1.
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        } else {
            // Move the accessed key-value pair to the front of the list (most
            // recently used)
            auto it = cache[key];
            int value = it->second;
            dq.erase(it); // Remove the old position of the key-value pair
            dq.push_front(
                {key, value}); // Insert at the front (most recently used)
            cache[key] =
                dq.begin(); // Update the hash map to point to the new position
            return value;
        }
    }

    // Put the key-value pair in the cache. If the key already exists, update
    // its value.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, remove the old node
            dq.erase(cache[key]);
        } else if (dq.size() == capacity) {
            // Cache is full, remove the least recently used key
            auto last = dq.back();
            cache.erase(last.first); // Remove from hashmap
            dq.pop_back();           // Remove from list (LRU eviction)
        }
        // Insert the new key-value pair at the front (most recently used)
        dq.push_front({key, value});
        cache[key] = dq.begin(); // Update hashmap with the new position
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */