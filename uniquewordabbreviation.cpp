class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto &word: dictionary) pool[trim(word)].insert(word);
    }
    
    bool isUnique(string word) {
        return pool.find(trim(word)) == pool.end() or (pool[trim(word)].size() == 1 and pool[trim(word)].find(word) != pool[trim(word)].end());
    }
    
    string trim(string word) {
        if (word.length() < 3) return word;
        word = word.front()+to_string(word.length()-2)+word.back();
        //cout << word << endl;
        return word;
    }
private:
    unordered_map<string, unordered_set<string>> pool;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
