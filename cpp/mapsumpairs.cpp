class TrieNode {
public:
    TrieNode(): val(0), isWord(false){}
    int val;
    bool isWord;
    unordered_map<char, TrieNode*> child;
};
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* ptr = root;
        for (auto &w: key) {
            if (ptr->child.find(w) == ptr->child.end()) {
                ptr->child[w] = new TrieNode();
            }  
            ptr = ptr->child[w];
        }
        ptr->isWord = true;
        ptr->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* ptr = root;
        for (auto &w: prefix) {
            if (ptr->child.find(w) == ptr->child.end()) return 0;
            ptr = ptr->child[w];
        }
        int sum = 0;
        dfs(ptr, sum);
        return sum;
    }
    void dfs(TrieNode* root, int &sum) {
        if (root == NULL) return;
        if (root->isWord) sum += root->val;
        for (auto it = root->child.begin(); it != root->child.end(); ++it) {
            dfs(it->second, sum);
        }
    }
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
