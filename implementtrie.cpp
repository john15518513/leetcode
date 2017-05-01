class TrieNode {
public:
    TrieNode(): isWord(false){
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
    
    TrieNode* child[26];
    bool isWord;
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = root;
        for (int i = 0; i < word.length(); i++) {
            if (ptr->child[word[i]-'a'] == NULL) {
                ptr->child[word[i]-'a'] = new TrieNode();
            }
            ptr = ptr->child[word[i]-'a'];
        }
        ptr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = root;
        for (int i = 0; i < word.length(); i++) {
            if (ptr->child[word[i]-'a'] == NULL) {
                return false;
            }
            ptr = ptr->child[word[i]-'a'];
        }
        return ptr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (ptr->child[prefix[i]-'a'] == NULL) {
                return false;
            }
            ptr = ptr->child[prefix[i]-'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
