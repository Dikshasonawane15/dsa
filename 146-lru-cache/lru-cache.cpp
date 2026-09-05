class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        // Move accessed node to front (most recently used)
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update existing key
            cache.erase(mp[key]);
        } else if (cache.size() == cap) {
            // Remove least recently used key
            int lruKey = cache.back().first;
            cache.pop_back();
            mp.erase(lruKey);
        }

        // Insert new/updated key at front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};