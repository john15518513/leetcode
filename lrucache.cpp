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

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity) {
        
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        int val = map[key]->second;
        List.erase(map[key]);
        List.push_front(make_pair(key, val));
        map[key] = List.begin();
        return val;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            List.erase(map[key]);
        }
        else if (List.size() == _capacity) {
                map.erase(List.back().first);
                List.pop_back();
        }
        List.push_front(make_pair(key, value));
        map[key] = List.begin();
    }
private:
    int _capacity;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> List;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
