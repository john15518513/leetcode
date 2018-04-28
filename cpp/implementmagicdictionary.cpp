class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto &s: dict) {
            for (int i = 0; i < s.size(); i++) {
                string tmp = s.substr(0, i) + s.substr(i+1);
                map[tmp].push_back(make_pair(i, s[i]));
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            string tmp = word.substr(0, i) + word.substr(i+1);
            if (map.find(tmp) != map.end()) {
                for (auto &e: map[tmp]) {
                    if (e.second != word[i] and i == e.first) return true;
                }
            }
        }
        return false;
    }
    unordered_map< string, vector< pair<int, char> > > map;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
