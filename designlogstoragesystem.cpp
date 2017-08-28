class LogSystem {
   
public:
    LogSystem() {
        index = {{"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}}; 
    }
    
    void put(int id, string timestamp) {
        timestamps[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> res;
        int idx = index[gra];
        for(auto &n: timestamps) {
            if (n.first.substr(0, idx) >= s.substr(0, idx) and n.first.substr(0, idx) <= e.substr(0, idx)) res.push_back(n.second);
        }
        return res;
    }
private:
    unordered_map<string, int> timestamps;
    unordered_map<string, int> index;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
