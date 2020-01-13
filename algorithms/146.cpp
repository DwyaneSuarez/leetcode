class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        used = 0;
    }

    int get(int key) {
        if (index.count(key)) {
            int value = index[key]->second;
            cache.splice(cache.begin(), cache, index[key]);
            return value;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (!index.count(key)) {
            if (used == cap) {
                int delkey = cache.back().first;
                index.erase(delkey);
                cache.pop_back();
                --used;
            }
            cache.push_front({key, value});
            index[key] = cache.begin();
            ++used;
        } else {
            index[key]->second = value;
            cache.splice(cache.begin(), cache, index[key]);
        }
    }
private:
    int cap;
    int used;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> index;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
