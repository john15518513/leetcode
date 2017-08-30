class TrieNode {
public:
    TrieNode(): isWord(false) {
        for (int i = 0; i < 26; i++) child.push_back(NULL);
    }
    bool isWord;
    vector<TrieNode*> child;
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* ptr = root;
        for (auto &s: word) {
            if (ptr->child[s-'a'] == NULL) {
                ptr->child[s-'a'] = new TrieNode();
            }
            ptr = ptr -> child[s-'a'];
        }
        ptr->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);
    }
    bool dfs(TrieNode* ptr, string &word, int index) {
        for (int i = index; i < word.size(); i++) {
            if (!ptr) return false;
            if (word[i] != '.') ptr = ptr->child[word[i]-'a'];
            else if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (dfs(ptr->child[j], word, i+1)) return true;
                }
                return false;
            }
            else break;
        }
        //return true;
        return ptr && ptr->isWord;
    }
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
