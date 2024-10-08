class LFUCache {
private:
    int capacity;
    int minFreq; // Track the minimum frequency in the cache
    unordered_map<int, int> keyValue; // Stores {key, value}
    unordered_map<int, int> keyFreq;  // Stores {key, frequency}
    unordered_map<int, list<int>> freqList;  // Stores {frequency, list of keys}
    unordered_map<int, list<int>::iterator> keyPos; // Stores {key, position in the frequency list}
    
public:
    // Constructor to initialize cache with a given capacity
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    // Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) {
            return -1; // Key not found
        }
        
        // Increment the frequency of the key
        updateFrequency(key);
        
        // Return the value of the key
        return keyValue[key];
    }
    
    // Put the key-value pair in the cache. If the key already exists, update its value.
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyValue.find(key) != keyValue.end()) {
            // Key already exists, update its value and increment the frequency
            keyValue[key] = value;
            updateFrequency(key);
        } else {
            // Cache is full, need to evict the least frequently used key
            if (keyValue.size() == capacity) {
                evictLFU();
            }
            
            // Insert the new key-value pair
            keyValue[key] = value;
            keyFreq[key] = 1;  // New key has frequency 1
            freqList[1].push_front(key);  // Insert into the list of keys with frequency 1
            keyPos[key] = freqList[1].begin();  // Save the position of the key in the list
            minFreq = 1;  // Since this is a new key, the minimum frequency is now 1
        }
    }
    
private:
    // Increment the frequency of the key and move it to the corresponding frequency list
    void updateFrequency(int key) {
        int freq = keyFreq[key];
        // Remove the key from its current frequency list
        freqList[freq].erase(keyPos[key]);
        
        // If the current frequency list is empty and it was the minimum frequency, increment minFreq
        if (freqList[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        
        // Increment the frequency
        keyFreq[key]++;
        int newFreq = keyFreq[key];
        
        // Add the key to the new frequency list
        freqList[newFreq].push_front(key);
        keyPos[key] = freqList[newFreq].begin();
    }
    
    // Evict the least frequently used key
    void evictLFU() {
        // The key to evict is at the back of the minimum frequency list
        int keyToEvict = freqList[minFreq].back();
        freqList[minFreq].pop_back();  // Remove the key from the frequency list
        
        if (freqList[minFreq].empty()) {
            freqList.erase(minFreq);  // Clean up if the list is empty
        }
        
        // Erase the key from all maps
        keyValue.erase(keyToEvict);
        keyFreq.erase(keyToEvict);
        keyPos.erase(keyToEvict);
    }
};
