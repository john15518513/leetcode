class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (valFreq.count(key) == 0) return -1;
        valFreq[key].second += 1;
        auto freq = valFreq[key].second;
        auto it = keyList[key];
        keyList.erase(key);
        freqKey[freq-1].erase(it);
        if (freqKey[freq-1].size() == 0) {
            freqKey.erase(freq-1);
            if (minFreq == freq-1)
                    minFreq = freq;
        }
        freqKey[freq].push_front(key);
        keyList[key] = freqKey[freq].begin();
        return valFreq[key].first;
    }
    
    void put(int key, int value) {
        if (_capacity <= 0) return;
        if (valFreq.count(key) == 0 and size == _capacity) {
            auto evictKey = freqKey[minFreq].back();
            freqKey[minFreq].pop_back();
            valFreq.erase(evictKey);
            keyList.erase(evictKey);
            if (freqKey[minFreq].size() == 0) freqKey.erase(minFreq);
            minFreq = 1;
            freqKey[minFreq].push_front(key);
            keyList[key] = freqKey[minFreq].begin();
            valFreq[key] = make_pair(value, minFreq);
        }
        else if (valFreq.count(key) == 0) {
            minFreq = 1;
            freqKey[minFreq].push_front(key);
            keyList[key] = freqKey[minFreq].begin();
            valFreq[key] = make_pair(value, minFreq);
            size++;
        }
        else {
            valFreq[key].second += 1;
            valFreq[key].first = value;
            auto freq = valFreq[key].second;
            auto it = keyList[key];
            keyList.erase(key);
            freqKey[freq-1].erase(it);
            if (freqKey[freq-1].size() == 0) {
                freqKey.erase(freq-1);
                if (minFreq == freq-1)
                    minFreq = freq;
            }
            freqKey[freq].push_front(key);
            keyList[key] = freqKey[freq].begin();
        }
        
    }
private:
    int _capacity;
    int minFreq;
    int size;
    unordered_map<int, pair<int, int>> valFreq;
    unordered_map<int, list<int>::iterator> keyList;
    unordered_map<int, list<int>> freqKey; 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
