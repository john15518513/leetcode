class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity) {
        
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        auto it = cache[key];
        int value = it->second;
        used.erase(it);
        used.push_front({key, value});
        cache[key] = used.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            used.erase(it);
            used.push_front({key, value});
        }
        else {
            if (used.size() < _capacity) {
                used.push_front({key,value});
            }
            else {
                //auto it = used.end()
                auto _key = used.back().first;
                used.pop_back();
                cache.erase(_key);
                used.push_front({key,value});
            }
        }
        cache[key] = used.begin();
        
    }
private:
    unordered_map<int, list<pair<int, int> >::iterator> cache;
    list<pair<int, int> > used;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
